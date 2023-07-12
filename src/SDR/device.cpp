#include "device.h"
Device::Device(Context *ctx)
{
    ctx_ = ctx;
    dev_ = iio_context_find_device(ctx_->context(), "ad9361-phy");
    //    iio_context_get_device(ctx_->context(), 2);
    if (dev_ == nullptr)
    {
        perror("Acquiring AD9361 streaming devices failed!\n");
    }
    stop_rx();

    tx_buffer = nullptr;
    rx_fc = 0;
    rx_fs = 0;
    rx_bw = 0;
    tx_stop_ = true;
}

iio_device *Device::device() const
{
    return dev_;
}

void Device::set_rx_gain(double gain, int channel)
{
    this->set_ad9361_rx_gain(RX, (int)gain, channel);
}

void Device::set_rx_samplerate(double sample_rate, int channel)
{
    if (this->set_ad9361_fs_hz(RX, channel, (long long)sample_rate))
    {
        rx_fs = (int32_t)sample_rate;
    }
}

void Device::set_rx_bandwidth(double bandwidth, int channel)
{
    if (this->set_ad9361_bd_hz(RX, channel, (long long)bandwidth))
    {
        rx_bw = (int32_t)bandwidth;
    }
}

void Device::set_rx_lo_frequency(long long frequency)
{
    if (this->set_ad9361_lo_hz(RX, (long long)frequency) == true)
    {
        rx_fc = (int32_t)frequency;
    }
}

bool Device::is_rx_running()
{
    return rx_stop_ == false;
}

int32_t Device::rx_lo_frequency()
{
    return rx_fc;
}

int32_t Device::rx_samplerate()
{
    return rx_fs;
}

int32_t Device::rx_bandwidth()
{
    return rx_bw;
}

void Device::set_tx_gain(double gain, int channel)
{
    this->set_ad9361_rx_gain(TX, (int)gain, channel);
}

void Device::set_tx_samplerate(double sample_rate, int channel)
{
    this->set_ad9361_fs_hz(TX, channel, (long long)sample_rate);
}

void Device::set_tx_bandwidth(double bandwidth, int channel)
{
    this->set_ad9361_bd_hz(TX, channel, (long long)bandwidth);
}

bool Device::set_tx_lo_frequency(long long frequency)
{
    return this->set_ad9361_lo_hz(TX, (long long)frequency);
}

bool Device::is_tx_runnig()
{
    return tx_stop_ == false;
}

void Device::rx(RxCallback rx_callback, int rx_size)
{
    if (rx_stop_ == false)
    {
        printf("rx is running\n");
        return;
    }
    auto ctx = this->ctx_;
    auto dev = iio_context_find_device(ctx->context(), "cf-ad9361-lpc");
    rx_stop_ = false;
    rx_thread_ = std::thread(&Device::_rx_thread, this, dev, rx_size, rx_callback);
    rx_thread_.detach();
    //    _rx_thread(dev,rx_size,queue);
}

void Device::stop_rx()
{
    rx_stop_ = true;
}

// void Device::tx(Buffer& queue, int tx_size)
//{
//     if (tx_stop_ == false) {
//         printf("tx is running\n");
//         return;
//     }
//     auto ctx = this->ctx_;
//     auto dev = iio_context_find_device(ctx->context(), "cf-ad9361-dds-core-lpc");
//     tx_stop_ = false;
//     tx_thread_ = std::thread(&Device::_tx_thread, this, dev, tx_size, std::ref(queue));
//     tx_thread_.detach();
// }

// void Device::stop_tx()
//{
//     tx_stop_ = true;
// }

int Device::tx_allocate_buffer(int sample_point_size)
{
    if (tx_stop_ == false)
    {
        printf("tx is running\n");
        return -1;
    }
    tx_stop_ = false;

    auto ctx = this->ctx_;

    auto ad9361_dds = iio_context_find_device(ctx->context(), "cf-ad9361-dds-core-lpc");

    IIO_ENSURE(get_ad9361_stream_ch(ctx->context(), TX, ad9361_dds, 0, &tx_channel.tx_i) && "TX chan i not found");
    IIO_ENSURE(get_ad9361_stream_ch(ctx->context(), TX, ad9361_dds, 1, &tx_channel.tx_q) && "TX chan q not found");

    iio_channel_enable(tx_channel.tx_i);
    iio_channel_enable(tx_channel.tx_q);

    tx_buffer = iio_device_create_buffer(ad9361_dds, sample_point_size, true);
    if (!tx_buffer)
    {
        char buf[256];
        iio_strerror(errno, buf, sizeof(buf));
        fprintf(stderr, "Unable to allocate TX buffer: %s\n", buf);
        return -2;
    }

    tx_sample_point_size = sample_point_size;

    return 1;
}

int Device::tx_reallocate_buffer(int sample_point_size)
{
    tx_free_buffer();
    return tx_allocate_buffer(sample_point_size);
}

int Device::tx_push_data(const Vci &data)
{
    int sample_point_size = data.size();
    if (sample_point_size > tx_sample_point_size)
    {
        printf("Sample data point exceed max point\n");
        return -1;
    }

    void *start = iio_buffer_first(tx_buffer, tx_channel.tx_i);

    int16_t *pData = (int16_t *)start;
    for (int i = 0; i < sample_point_size; i++)
    {
        pData[i * 2] = (data[i].real() << 4);
        pData[i * 2 + 1] = (data[i].imag() << 4);
    }
    printf("update data , data size = %d\n", sample_point_size);

    size_t ret = iio_buffer_push(tx_buffer);
    if (ret < 0)
    {
        char buf[256];
        iio_strerror(-(int)ret, buf, sizeof(buf));
        fprintf(stderr, "Unable to push buffer: %s\n", buf);
        return -2;
    }

    return 1;
}

int Device::tx_free_buffer()
{
    //    int sample_point_size = data.size();
    if (tx_buffer != nullptr)
    {
        //        tx_push_data(Vci(tx_sample_point_size,ComplexInt16(0,0)));
        iio_buffer_destroy(tx_buffer);
        iio_channel_disable(tx_channel.tx_i);
        iio_channel_disable(tx_channel.tx_q);

        //        set_tx_lo_frequency()
        tx_buffer = nullptr;
        tx_stop_ = true;
    }
    return 1;
}

bool Device::alarm(unsigned int &value, int ch)
{
    return this->_get_alarm(value, ch);
}

bool Device::set_alarm(unsigned long value, int chid)
{
    return this->_set_alarm(value, chid);
}

bool Device::get_switch(unsigned int &value, int ch)
{
    return this->_get_switch(value, ch);
}

bool Device::set_switch(unsigned long value, int chid)
{
    return this->_set_switch(value, chid);
}

bool Device::get_temp(double &value, int ch)
{
    return this->_get_temp(value, ch);
}

bool Device::set_ofmd(unsigned long value, int chid)
{
    return this->_set_ofmd(value, chid);
}

bool Device::get_ADtemp(double &value, int ch)
{
    return this->_get_ADtemp(value, ch);
}

bool Device::set_FPGAMode(unsigned long value, int chid)
{
    return this->_set_FPGAMode(value, chid);
}

void Device::_rx_thread(iio_device *dev, int rx_size, RxCallback rx_callback)
{

    iio_channel *rx0_i = NULL;
    iio_channel *rx0_q = NULL;
    //    iio_channel* rx1_i = NULL;
    //    iio_channel* rx1_q = NULL;

    auto ctx = this->ctx_->context();
    printf("* Initializing AD9361 IIO streaming channels\n");
    get_ad9361_stream_ch(ctx, RX, dev, 0, &rx0_i);
    get_ad9361_stream_ch(ctx, RX, dev, 1, &rx0_q);
    //    get_ad9361_stream_ch(ctx, RX, dev, 2, &rx1_i);
    //    get_ad9361_stream_ch(ctx, RX, dev, 3, &rx1_q);

    iio_channel_enable(rx0_i);
    iio_channel_enable(rx0_q);

    //    iio_channel_enable(rx1_i);
    //    iio_channel_enable(rx1_q);

    long long buff_size = rx_size;
    printf("* Creating non-cyclic IIO buffers\n");
    iio_buffer *rxbuf = iio_device_create_buffer(dev, buff_size, false);

    Vci buffer;
    buffer.resize(buff_size);
    printf("rx start!\n");
    char *pBuffer = (char *)buffer.data();
    long long fs = rx_fs;
    //    const double t1 = (double)buff_size / (double)fs;
    //    auto start = std::chrono::high_resolution_clock::now();
    while (rx_stop_ == false)
    {
        if (rx_stop_ == true)
        {
            printf("while loop reached\n");
        }

        int ret = iio_buffer_refill(rxbuf);
        //        iio_buffer_get_data()

        //        auto end = std::chrono::high_resolution_clock::now();
        //        auto t = std::chrono::duration<double, std::milli>(end - start).count();
        //        printf("fs = %lld,point = %d,t1:%.9fms t2:%.9f ms\n",fs,rx_size,t1*1e3,t);
        //        start = std::chrono::high_resolution_clock::now();
        //        start = end;

        if (ret < 0)
        {
            char buf[256];
            iio_strerror(-(int)ret, buf, sizeof(buf));
            fprintf(stderr, "Unable to refill buffer: %s\n", buf);
            break;
        }
        //        int16_t* p_end = (int16_t*)iio_buffer_end(rxbuf);
        int16_t *p_first = (int16_t *)iio_buffer_first(rxbuf, rx0_i);
        //        ptrdiff_t p_inc = iio_buffer_step(rxbuf);
        //        printf("data size : %lld\n", (p_end - p_first) * 2);
        //        memcpy(pBuffer, p_first, (p_end - p_first) * 2);

        for (int i = 0; i < buffer.size(); i++)
        {
            buffer[i].real(p_first[2 * i]);
            buffer[i].imag(p_first[2 * i + 1]);
        }

        //        queue.enqueue(buffer);
    }
    iio_channel_disable(rx0_i);
    iio_channel_disable(rx0_q);
    iio_buffer_destroy(rxbuf);
    printf("rx finished!\n");
}

int Device::_getIQData()
{
    struct iio_device *tx;
    struct iio_device *rx;
    iio_channel *rx0_i = NULL;
    iio_channel *rx0_q = NULL;

    // RX and TX sample counters
    size_t nrx = 0;
    size_t ntx = 0;

    // Stream configurations
    struct stream_cfg rxcfg;
    struct stream_cfg txcfg;

    // RX stream config
    rxcfg.bw_hz = MHZ(56);    // 2 MHz rf bandwidth
    rxcfg.fs_hz = MHZ(61.44);    // 2.5 MS/s rx sample rate
    rxcfg.lo_hz = GHZ(2.47);     // 2.5 GHz rf frequency
    rxcfg.rfport = "B_BALANCED"; // port A (select for rf freq.)

    auto ctx = this->ctx_;

    IIO_ENSURE(iio_context_get_devices_count(ctx->context()) > 0 && "No devices");

    IIO_ENSURE(get_ad9361_stream_dev(ctx->context(), RX, &rx) && "No rx dev found");

    printf("* Configuring AD9361 for streaming\n");

    IIO_ENSURE(cfg_ad9361_streaming_ch(ctx->context(), &rxcfg, RX, 0) && "RX port 0 not found");

    printf("* Initializing AD9361 IIO streaming channels\n");

    IIO_ENSURE(get_ad9361_stream_ch(ctx->context(), RX, rx, 0, &rx0_i) && "RX chan i not found");
    IIO_ENSURE(get_ad9361_stream_ch(ctx->context(), RX, rx, 1, &rx0_q) && "RX chan q not found");

    printf("* Enabling IIO streaming channels\n");

    iio_channel_enable(rx0_i);
    iio_channel_enable(rx0_q);

    iio_buffer *rxbuf = iio_device_create_buffer(rx, NCOLS * 4 * 100, false);
    if (!rxbuf)
    {
        perror("Could not create RX buffer");
        return 0;
    }

    ssize_t nbytes_rx;
    char *p_dat, *p_end;
    ptrdiff_t p_inc;
    p_inc = iio_buffer_step(rxbuf);
    p_end = (char *)iio_buffer_end(rxbuf);
    p_dat = (char *)iio_buffer_first(rxbuf, rx0_i);

    printf("p_inc:%ld\n", p_inc);

    fflush(0);

    // Refill RX buffer
    nbytes_rx = iio_buffer_refill(rxbuf);
    if (nbytes_rx < 0)
    {
        printf("Error refilling buf %d\n", (int)nbytes_rx);
        return 0;
    }
    printf("nbytes_rx: %d\n", nbytes_rx);
    printf("p_end-p_dat: %lld\n", p_end - p_dat);

    int16_t *p_first = (int16_t *)iio_buffer_first(rxbuf, rx0_i);
    //        ptrdiff_t p_inc = iio_buffer_step(rxbuf);
    //        printf("data size : %lld\n", (p_end - p_first) * 2);
    //        memcpy(pBuffer, p_first, (p_end - p_first) * 2);

    Vci buffer;
    buffer.resize(nbytes_rx / p_inc);

    FILE *fp;
    fp = fopen("./iq11.txt", "w+");

    for (; p_dat < p_end; p_dat += p_inc)
    {
        const int16_t i = ((int16_t *)p_dat)[0]; // Real (I)
        const int16_t q = ((int16_t *)p_dat)[1]; // Imag (Q)
        /* Process here */
        // printf("i = % 4i", i);
        // printf(" | q = % 4i\n", q);
        fprintf(fp,"real:%d imag:%d\n", q, i);
    }
    // for (int i = 0; i < buffer.size(); i++)
    // {
    //     buffer[i].real(p_first[2 * i]);
    //     buffer[i].imag(p_first[2 * i + 1]);

    //     fprintf(fp,"real:%d imag:%d\n", buffer[i].real(), buffer[i].imag());
    // }

    iio_channel_disable(rx0_i);
    iio_channel_disable(rx0_q);
    iio_buffer_destroy(rxbuf);
}


/**
 * @brief 实时修改频点
 * @param ant_sw 天线开关
 * @param lo_hz 频点，单位hz，如2450000000
 */
void Device::set_freq(long long lo_hz, uint32_t ant_sw)
{
    struct iio_channel *chn = NULL;
    auto ctx = this->ctx_;
    if (!get_lo_chan(ctx->context(), RX, &chn))
    {
        return;
    }
    uint param = (ant_sw & 0xff) << 0;
    wr_ch_lli(chn, "frequency", lo_hz);
    wr_ch_lli(chn, "ant_switch", param);
}

void Device::set_bandwidth(long long param)
{
    struct iio_channel *chn = NULL;
    auto ctx = this->ctx_;
    if (!get_phy_chan(ctx->context(), RX, 0, &chn))
    {
        return;
    }
    wr_ch_lli(chn, "rf_bandwidth", param);
}
void Device::set_freq_sample(long long param)
{
    struct iio_channel *chn = NULL;
    auto ctx = this->ctx_;
    if (!get_phy_chan(ctx->context(), RX, 0, &chn))
    {
        return;
    }
    wr_ch_lli(chn, "sampling_frequency", param);
}
void Device::set_gain(int gain)
{
    struct iio_channel *chn = NULL;
    auto ctx = this->ctx_;
    if (!get_phy_chan(ctx->context(), RX, 0, &chn))
    {
        return;
    }
    wr_ch_str(chn, "gain_control_mode", "manual");
    wr_ch_lli(chn, "hardwaregain", gain);
}