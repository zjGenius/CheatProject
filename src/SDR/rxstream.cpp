#include "rxstream.h"

RxStream::RxStream()
{
//    dev_ = dev;
//    ctx_ = ctx;
}

void RxStream::setFreq(long long freq)
{
//    auto chn = iio_device_find_channel(dev_->device(), "altvoltage0", true);
//    iio_channel_attr_write_longlong(chn, "frequency", freq); /* RX LO frequency 2.5GHz */
}

void RxStream::setFs(long long fs)
{
//    auto chn = iio_device_find_channel(dev_->device(), "voltage0", false);
//    iio_channel_attr_write_longlong(chn,"sampling_frequency",fs); /* RX baseband rate 2.5 MSPS */
}

void RxStream::receive()
{
//    auto dev = dev_->device();
////    auto ctx = dev_->device()
//    struct iio_channel* rx0_i, * rx0_q;
//    struct iio_buffer* rxbuf;
//    dev = iio_context_find_device(ctx_->context(), "cf-ad9361-lpc");
//    rx0_i = iio_device_find_channel(dev, "voltage0", 0);
//    rx0_q = iio_device_find_channel(dev, "voltage1", 0);

//    iio_channel_enable(rx0_i);
//    iio_channel_enable(rx0_q);

//    rxbuf = iio_device_create_buffer(dev, 4096, false);

//    bool track = false;
//    while (true) {

//        if (track == false) {
//            printf("while loop reached\n");
//            track = true;
//        }

//        iio_buffer_refill(rxbuf);


//        char *p_end = (char*)iio_buffer_end(rxbuf);
//        char* p_start = (char*)iio_buffer_first(rxbuf, rx0_i);
//        ptrdiff_t p_inc = iio_buffer_step(rxbuf);

//        printf("data len = %lld\n", p_end - p_start);

//        for (; p_start < p_end; p_start += p_inc, p_start += p_inc) {
//            const int16_t i = ((int16_t*)p_start)[0]; // Real (I)
//            const int16_t q = ((int16_t*)p_start)[1]; // Imag (Q)
//            /* Process here */
//            //printf("i = % 4i", i);
//            //printf(" | q = % 4i\n", q);
//        }
//    }
//    iio_buffer_destroy(rxbuf);

//    printf("receive finished");
}
