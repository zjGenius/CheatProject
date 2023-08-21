#ifndef DEVICE_H
#define DEVICE_H

#include "Utils.hpp"
#include "context.h"
#include <atomic>
#include <complex.h>
#include <functional>
#include <thread>
#include <vector>
#include <signal.h>
class Device
{
public:
    Device(Context *ctx);
    iio_device *device() const;

    using ComplexInt16 = std::complex<int16_t>;
    using Vci = std::vector<ComplexInt16>;
    using RxCallback = std::function<void(ComplexInt16 *, long long size)>;

    void set_rx_gain(double gain, int channel);
    void set_rx_samplerate(double sample_rate, int channel);
    void set_rx_bandwidth(double bandwidth, int channel);
    void set_rx_lo_frequency(long long frequency);
    bool is_rx_running();

    int32_t rx_lo_frequency();
    int32_t rx_samplerate();
    int32_t rx_bandwidth();

    void set_tx_gain(double gain, int channel);
    void set_tx_samplerate(double sample_rate, int channel);
    void set_tx_bandwidth(double bandwidth, int channel);
    bool set_tx_lo_frequency(long long frequency);
    bool is_tx_runnig();

    void rx(RxCallback rx_callback, int rx_size = 4096);
    void stop_rx();

    //    void tx(Buffer& queue, int tx_size = 4096);
    //    void stop_tx();

    // V2 cyclic buffer;
    int tx_allocate_buffer(int sample_point_size);
    int tx_reallocate_buffer(int sample_point_size);
    int tx_push_data(const Vci &data);
    int tx_free_buffer();

    bool alarm(unsigned int &value, int ch = 0);
    bool set_alarm(unsigned long value, int chid = 0);
    bool get_switch(unsigned int &value, int ch = 0);
    bool set_switch(unsigned long value, int chid = 0);
    bool get_temp(double &value, int ch = 0);
    bool set_ofmd(unsigned long value, int chid = 0);
    bool get_ADtemp(double &value, int ch = 0);
    bool set_FPGAMode(unsigned long value, int chid);
    // new jun creator
    int _getIQData();
    void set_freq(long long lo_hz, uint32_t ant_sw);
    void set_bandwidth(long long param);
    void set_freq_sample(long long param);
    void set_gain(int gain);

private:
    void _rx_thread(iio_device *dev, int rx_size, RxCallback rx_callback);

    bool _get_alarm(unsigned int &value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        //        printf("%s\n", name);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        char _tmp_value[16];
        int ret = iio_channel_attr_read(chn, "alarm", _tmp_value, sizeof(_tmp_value));
        if (ret < 0)
        {
            char buf[256];
            iio_strerror(errno, buf, sizeof(buf));
            printf("error = %s\n", buf);
        }
        sscanf(_tmp_value, "[%08x]", &value);
        return ret == 0;
    }

    bool _set_alarm(unsigned int value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        unsigned long long _tmp_value = 0;
        int ret = iio_channel_attr_write_longlong(chn, "alarm", value);
        return ret == 0;
    }

    bool _get_switch(unsigned int &value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        //        printf("%s\n", name);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        char _tmp_value[16];
        int ret = iio_channel_attr_read(chn, "ant_switch", _tmp_value, sizeof(_tmp_value));
        if (ret < 0)
        {
            char buf[256];
            iio_strerror(errno, buf, sizeof(buf));
            printf("error = %s\n", buf);
        }
        sscanf(_tmp_value, "[%08x]", &value);
        return ret == 0;
    }

    bool _set_switch(unsigned int value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        unsigned long long _tmp_value = 0;
        int ret = iio_channel_attr_write_longlong(chn, "ant_switch", value);
        return ret == 0;
    }

    bool _set_ofmd(unsigned int value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        unsigned long long _tmp_value = 0;
        int ret = iio_channel_attr_write_longlong(chn, "ofdm_param", value);
        return ret == 0;
    }

    bool _set_FPGAMode(unsigned int value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "altvoltage%d", chid);
        struct iio_channel *chn = nullptr;
        get_lo_chan(ctx, TX, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        unsigned long long _tmp_value = 0;
        int ret = iio_channel_attr_write_longlong(chn, "platform", value);
        return ret == 0;
    }

    bool _get_temp(double &value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "voltage%d", chid);
        //        printf("%s\n", name);
        struct iio_channel *chn = nullptr;
        get_adc_chan(ctx, chid, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        char _tmp_value[16];
        int ret = iio_channel_attr_read(chn, "scale", _tmp_value, sizeof(_tmp_value));
        if (ret < 0)
        {
            char buf[256];
            iio_strerror(errno, buf, sizeof(buf));
            printf("error = %s\n", buf);
        }
        sscanf(_tmp_value, "%lf", &value);
        return ret == 0;
    }

    bool _get_ADtemp(double &value, int chid)
    {
        auto ctx = this->ctx_->context();
        char name[64]{0};
        snprintf(name, sizeof(name), "in_voltage%d", chid);
        //        printf("%s\n", name);
        struct iio_channel *chn = nullptr;
        get_adc_chan(ctx, chid, &chn);
        if (chn == nullptr)
        {
            printf("error\n");
            return false;
        }
        char _tmp_value[16];
        int ret = iio_channel_attr_read(chn, "raw", _tmp_value, sizeof(_tmp_value));
        if (ret < 0)
        {
            char buf[256];
            iio_strerror(errno, buf, sizeof(buf));
            printf("error = %s\n", buf);
        }
        sscanf(_tmp_value, "%lf", &value);
        return ret == 0;
    }

    bool set_ad9361_rx_gain(iodev type, long long value, int chid)
    {
        printf("* Acquiring AD9361 %s gain channel %d gain = %lld\n", type == TX ? "TX" : "RX", chid, value);
        struct iio_channel *chn = nullptr;
        auto ctx = this->ctx_->context();
        if (!get_phy_chan(ctx, type, chid, &chn))
        {
            return false;
        }
        if (type == RX)
        { // 指定手动配置增益
            wr_ch_str(chn, "gain_control_mode", "manual");
        }

        wr_ch_lli(chn, "hardwaregain", value);
        //                wr_ch_str(chn, "rf_port_select", "A_BALANCED");
        return true;
    }

    bool set_ad9361_fs_hz(iodev type, int chid, long long int fs)
    {
        printf("* Acquiring AD9361 %s fs channel %d fs = %.3fMHz\n", type == TX ? "TX" : "RX", chid, (double)fs / 1e6);
        auto ctx = this->ctx_->context();
        struct iio_channel *chn = nullptr;
        if (!get_phy_chan(ctx, type, chid, &chn))
        {
            return false;
        }
        wr_ch_lli(chn, "sampling_frequency", fs);
        return true;
    }

    bool set_ad9361_bd_hz(iodev type, int chid, long long int bd_hz)
    {
        printf("* Acquiring AD9361 %s bw channel %d bw = %.3fHMz\n", type == TX ? "TX" : "RX", chid, (double)bd_hz / 1e6);
        auto ctx = this->ctx_->context();
        struct iio_channel *chn = nullptr;
        if (!get_phy_chan(ctx, type, chid, &chn))
        {
            return false;
        }
        wr_ch_lli(chn, "rf_bandwidth", bd_hz);
        return true;
    }

    bool set_ad9361_lo_hz(iodev type, long long int lo_hz)
    {
        auto ctx = this->ctx_->context();
        struct iio_channel *chn = nullptr;
        if (!get_lo_chan(ctx, type, &chn))
        {
            return false;
        }
        int ret = wr_ch_lli(chn, "frequency", lo_hz);
        printf("* Acquiring AD9361 %s lo channel freq = %lldHz\n", type == TX ? "TX" : "RX", lo_hz);

        return ret == 0;
    }

    struct iio_device *get_ad9361_phy(iio_context *ctx)
    {
        struct iio_device *dev = iio_context_find_device(ctx, "ad9361-phy");
        return dev;
    }

private:
    iio_device *dev_;
    Context *ctx_;
    long long _fs;

    // Rx
    std::atomic_int32_t rx_fc;
    std::atomic_int32_t rx_fs;
    std::atomic_int32_t rx_bw;

    typedef struct iio_IQ_channel
    {
        iio_channel *tx_i;
        iio_channel *tx_q;
    } iio_IQ_channel;

    // V2 Tx
    iio_IQ_channel tx_channel;
    iio_buffer *tx_buffer;
    int tx_sample_point_size;

    // thread
    std::atomic_bool rx_stop_;
    std::thread rx_thread_;

    std::atomic_bool tx_stop_;
    std::thread tx_thread_;
};

#endif // DEVICE_H
