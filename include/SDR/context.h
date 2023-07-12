#ifndef CONTEXT_H
#define CONTEXT_H

#include <./3rdparty/iio/include/iio.h>
#include <string>

class Context {
public:
    enum Type {
        NETWORK,
    };
    Context();
    Context(const std::string& addr,Type type= Type::NETWORK);
    ~Context();

    Context operator=(Context &ctx) = delete;
    Context(Context &ctx) = delete;

    iio_context* context()const;

private:
    std::string addr_;
    iio_context* pCtx_;
};

#endif // CONTEXT_H
