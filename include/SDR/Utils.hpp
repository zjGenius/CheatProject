#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstddef>
#include <./3rdparty/iio/include/iio.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "./Tools/Tools.hpp"
#define M_PI 3.14159265358979323846
#define M_2PI (2 * M_PI)

#define NROWS 800       // 数据行数
#define NCOLS 128       // 数据列数

// #define KHZ(x) ((long long)(x * 1000.0 + .5))
// #define MHZ(x) ((long long)(x * 1000000.0 + .5))
// #define GHZ(x) ((long long)(x * 1000000000.0 + .5))
using namespace Tools;
#define IIO_ENSURE(expr)                                                             \
    {                                                                                \
        if (!(expr))                                                                 \
        {                                                                            \
            (void)fprintf(stderr, "assertion failed (%s:%d)\n", __FILE__, __LINE__); \
            (void)abort();                                                           \
        }                                                                            \
    }

enum iodev
{
    RX,
    TX
};

struct stream_cfg
{
    long long bw_hz;    // Analog banwidth in Hz
    long long fs_hz;    // Baseband sample rate in Hz
    long long lo_hz;    // Local oscillator frequency in Hz
    const char *rfport; // Port name
};

/* check return value of attr_write function */
static void errchk(int v, const char *what)
{
    if (v < 0)
    {
        fprintf(stderr, "Error %d writing to channel \"%s\"\nvalue may not be supported.\n", v, what); /* shutdown()*/
    }
}

/* write attribute: long long int */
static int wr_ch_lli(struct iio_channel *chn, const char *what, long long val)
{
    return iio_channel_attr_write_longlong(chn, what, val);
}

/* write attribute: string */
static void wr_ch_str(struct iio_channel *chn, const char *what, const char *str)
{
    errchk(iio_channel_attr_write(chn, what, str), what);
}

/* static scratch mem for strings */
static char tmpstr[64];
/* helper function generating channel names */
static char *get_ch_name(const char *type, int id)
{
    snprintf(tmpstr, sizeof(tmpstr), "%s%d", type, id);
    return tmpstr;
}

/* returns ad9361 phy device */
static struct iio_device *get_ad9361_phy(struct iio_context *ctx)
{
    struct iio_device *dev = iio_context_find_device(ctx, "ad9361-phy");
    IIO_ENSURE(dev && "No ad9361-phy found");
    return dev;
}

/* returns switchAdc device */
static struct iio_device *get_switchAdc(struct iio_context *ctx)
{
    struct iio_device *dev = iio_context_find_device(ctx, "switchAdc");
    IIO_ENSURE(dev && "No ad9361-phy found");
    return dev;
}

/* finds AD9361 streaming IIO devices */
static bool get_ad9361_stream_dev(struct iio_context *ctx, enum iodev d, struct iio_device **dev)
{
    switch (d)
    {
    case TX:
        *dev = iio_context_find_device(ctx, "cf-ad9361-dds-core-lpc");
        return *dev != NULL;
    case RX:
        *dev = iio_context_find_device(ctx, "cf-ad9361-lpc");
        return *dev != NULL;
    default:
        IIO_ENSURE(0);
        return false;
    }
}

/* finds AD9361 streaming IIO channels */
static bool get_ad9361_stream_ch(__notused struct iio_context *ctx, enum iodev d, struct iio_device *dev, int chid, struct iio_channel **chn)
{
    *chn = iio_device_find_channel(dev, get_ch_name("voltage", chid), d == TX);
    if (!*chn)
        *chn = iio_device_find_channel(dev, get_ch_name("altvoltage", chid), d == TX);
    return *chn != NULL;
}

/* finds AD9361 phy IIO configuration channel with id chid */
static bool get_phy_chan(struct iio_context *ctx, enum iodev d, int chid, struct iio_channel **chn)
{
    switch (d)
    {
    case RX:
        *chn = iio_device_find_channel(get_ad9361_phy(ctx), get_ch_name("voltage", chid), false);
        return *chn != NULL;
    case TX:
        *chn = iio_device_find_channel(get_ad9361_phy(ctx), get_ch_name("voltage", chid), true);
        return *chn != NULL;
    default:
        IIO_ENSURE(0);
        return false;
    }
}

/* finds AD9361 local oscillator IIO configuration channels */
static bool get_lo_chan(struct iio_context *ctx, enum iodev d, struct iio_channel **chn)
{
    switch (d)
    {
        // LO chan is always output, i.e. true
    case RX:
        *chn = iio_device_find_channel(get_ad9361_phy(ctx), get_ch_name("altvoltage", 0), true);
        return *chn != NULL;
    case TX:
        *chn = iio_device_find_channel(get_ad9361_phy(ctx), get_ch_name("altvoltage", 1), true);
        return *chn != NULL;
    default:
        IIO_ENSURE(0);
        return false;
    }
}

/* finds switchAdc oscillator IIO configuration channels */
static bool get_adc_chan(struct iio_context *ctx, int chid, struct iio_channel **chn)
{
    *chn = iio_device_find_channel(get_switchAdc(ctx), get_ch_name("voltage", chid), false);
    return *chn != NULL;
}

inline double angle2rad(const double &a)
{
    return a * M_PI / 180.0;
}

inline double rad2angle(const double &r)
{
    return r * 180.0 / M_PI;
}


/* applies streaming configuration through IIO */
static bool cfg_ad9361_streaming_ch(struct iio_context *ctx, struct stream_cfg *cfg, enum iodev type, int chid)
{
    struct iio_channel *chn = NULL;

    // Configure phy and lo channels
    printf("* Acquiring AD9361 phy %s channel %d\n", type == TX ? "TX" : "RX", chid);
    if (!get_phy_chan(ctx, type, chid, &chn))
    {
        return false;
    }
    //    wr_ch_str(chn, "rf_port_select",     cfg->rfport);
    wr_ch_lli(chn, "rf_bandwidth", cfg->bw_hz);
    wr_ch_lli(chn, "sampling_frequency", cfg->fs_hz);
    //    wr_ch_lli(chn, "hardwaregain",60);

    // Configure LO channel
    printf("* Acquiring AD9361 %s lo channel\n", type == TX ? "TX" : "RX");
    if (!get_lo_chan(ctx, type, &chn))
    {
        return false;
    }
    wr_ch_lli(chn, "frequency", cfg->lo_hz);
    return true;
}

static std::vector<std::complex<double>> generateSingalF(double sample_fs = 2048e3, int sample_point_size = 4096, double delta_f = 1, double times = 1.0)
{
    double sample_delta_t = 1 / sample_fs;
    double sample_resolution = sample_fs / sample_point_size;
    double sample_step = sample_delta_t * sample_resolution;
    printf("sample_resolution = %fHz , delta_f = %.3fMHZ\n", sample_resolution, delta_f * sample_resolution / MHZ(1));
    delta_f /= times;
    //    printf("times = %f\n",times);
    std::vector<std::complex<double>> vec;
    double t = 0.0;
    //    printf("%.15f\n",sample_delta_t);
    for (int k = 0; k < sample_point_size; k++)
    {
        t = sample_step * k;
        double r = cos((M_2PI * t * delta_f));
        double i = sin((M_2PI * t * delta_f));
        vec.push_back(std::complex<double>(r, i));
    }
    return vec;
}

// complex float convert to complex int16
static std::vector<std::complex<int16_t>> complexF2I(const std::vector<std::complex<double>> &f_data, double ampl = 1024)
{

    // 数据小于1.0 按半量程计算
    // https://wiki.analog.com/resources/eval/user-guides/ad-fmcomms2-ebz/software/basic_iq_datafiles#binary_format
    double max_value = 1.0;
    for (int i = 0; i < f_data.size(); i++)
    {
        double max_r_i = std::fmax(f_data[i].real(), f_data[i].imag());
        max_value = std::fmax(max_value, max_r_i);
    }

    //    const double eps = 1e-9;
    //    if (max_value > 1.0) {
    //        max_value = 1.0;
    //    }

    //    std::for_each(f_data.begin(), f_data.end(), [max_value](std::complex<double>& e) { e /= max_value; });

    std::vector<std::complex<int16_t>> vec(f_data.size());
    double r = 0.0, i = 0.0;
    for (int k = 0; k < vec.size(); k++)
    {
        r = (double)f_data[k].real() * ampl / max_value;
        i = (double)f_data[k].imag() * ampl / max_value;
        vec[k].real((int16_t)r);
        vec[k].imag((int16_t)i);
    }

    return vec;
}

static std::vector<std::complex<int16_t>> generateSingalI(double sample_fs = 2048e3, int sample_point_size = 4096, int delta_f = 1, double times = 1.0)
{
    auto sample_data = generateSingalF(sample_fs, sample_point_size, delta_f, times);
    return complexF2I(sample_data, 2048);
}

// complex int16 convert to complex float
static std::vector<std::complex<double>> complexI2F(const std::vector<std::complex<int16_t>> &i_data)
{

    double max_value = 0;
    for (int i = 0; i < i_data.size(); i++)
    {
        double max_r_i = std::fmax(i_data[i].real(), i_data[i].imag());
        max_value = std::fmax(max_value, max_r_i);
    }

    std::vector<std::complex<double>> vec(i_data.size());
    double r = 0.0, i = 0.0;
    for (int k = 0; k < vec.size(); k++)
    {
        r = (double)i_data[k].real() / max_value;
        i = (double)i_data[k].imag() / max_value;
        vec[k].real(r);
        vec[k].imag(i);
    }
    return vec;
}
#include <iostream>
static std::vector<std::complex<int16_t>> compose_sig(const std::vector<std::complex<int16_t>> &sample_data, int sample_fs,
                                                      int tx_fs, std::vector<double> delta_f_list)
{
    if (delta_f_list.size() <= 1)
    { // 频点列表小于2不处理
        return sample_data;
    }

    const int sample_size = sample_data.size(); // 4096;
    const double sample_resolution = sample_fs / sample_size;
    const int sample_per = tx_fs / sample_fs;

    // conversion data;
    const int fs_times = tx_fs / sample_fs;                       // 采样倍数
    const double conversion_fs = sample_fs * fs_times;            // 采样率
    const int conversion_size = sample_size * fs_times;           // 数据点大小
    const double conversion_resolution = sample_fs / sample_size; // conversion_fs / conversion_size; // 分辨率
    const double conversion_per = tx_fs / conversion_fs;

    auto sample_data_f = complexI2F(sample_data);

    std::vector<std::complex<double>> result_data(conversion_size, std::complex<double>(0.0, 0.0));
    //    for (int i = 0; i < conversion_size; i++) {
    //        result_data[i] = sample_data_f[i / fs_times];
    //    }
    for (int k = 0; k < delta_f_list.size(); k++)
    {
        auto conversion_data_f = generateSingalF(conversion_fs, conversion_size, MHZ(delta_f_list[k]) / conversion_resolution, conversion_per);
        for (int i = 0; i < conversion_size; i++)
        {
            conversion_data_f[i] = conversion_data_f[i] * sample_data_f[i / fs_times]; //+ sample_data_f[i / fs_times];
            result_data[i] += conversion_data_f[i];
        }
    }

    int delta_f_list_size = delta_f_list.size();
    for (int i = 0; i < conversion_size; i++)
    {
        result_data[i] /= delta_f_list_size;
    }

    //    std::for_each(std::begin(result_data), std::end(result_data), [](auto value) { std::cout << value << std::endl; });

    std::vector<std::complex<int16_t>> result_data_i = complexF2I(result_data, 2048);

    return result_data_i;
}

#endif // UTILS_H
