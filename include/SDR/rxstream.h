#ifndef RXSTREAM_H
#define RXSTREAM_H


class RxStream
{
public:
    RxStream();

    void setFreq(long long freq);
    void setFs(long long fs);


    void receive();

private:


//    Device *dev_;
//    Context *ctx_;
};

#endif // RXSTREAM_H
