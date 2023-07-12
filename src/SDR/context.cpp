#include "context.h"

Context::Context()
{
    pCtx_ = iio_create_default_context();
}

iio_context* Context::context() const
{
    return pCtx_;
}
Context::Context(const std::string& addr, Type type)
{
    addr_ = addr;
    if (type == Type::NETWORK) {
        pCtx_ = iio_create_context_from_uri(addr.c_str());
    }
//    unsigned int nb_devices = iio_context_get_devices_count(pCtx_);

//    for (int i = 0; i < nb_devices; i++) {
//        const char *dev_id = NULL, *label = NULL, *name = NULL;
//        bool hit;

//        auto dev = iio_context_get_device(pCtx_, i);
//        auto nb_channels = iio_device_get_channels_count(dev);

//        if (!nb_channels)
//            continue;

//        hit = false;
//        for (auto j = 0; j < nb_channels; j++) {
//            struct iio_channel *ch = iio_device_get_channel(dev, j);

//            if (!iio_channel_is_scan_element(ch) ||
//                !iio_channel_is_output(ch))
//                continue;

//            hit = true;

//            dev_id = iio_device_get_id(dev);
//            label = iio_device_get_label(dev);
//            name = iio_device_get_name(dev);

//            printf("Example : " MY_NAME " -u %s -b 256 -s 1024 %s %s\n",
//                   iio_context_get_attr_value(pCtx_, "uri"),
//                   label ? label : name ? name : dev_id,
//                   iio_channel_get_id(ch));
//        }
//        if (hit)
//            printf("Example : " MY_NAME " -u %s -b 256 -s 1024 %s\n",
//                   iio_context_get_attr_value(pCtx_, "uri"),
//                   label ? label : name ? name : dev_id);
//    }

}


Context::~Context()
{
    if (pCtx_ != nullptr) {
        iio_context_destroy(pCtx_);
    }
}
