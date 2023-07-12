#ifndef STREAM_ARGS_H
#define STREAM_ARGS_H
#include <string>

class stream_args_t {

public:
    void set_bw(long long bw)
    {
        bw_hz = bw;
    }
    void set_fs(long long fs)
    {
        fs_hz = fs;
    }
    void set_freq(long long freq)
    {
        lo_hz = freq;
    }
    void set_rfport(const char* portname)
    {
        rfport = std::string(portname);
    }
    void set_buffer_size_(long long size)
    {
        buffer_size_ = size;
    }

    long long bandwidth()
    {
        return bw_hz;
    }
    long long fs()
    {
        return fs_hz;
    }
    long long freq()
    {
        return lo_hz;
    }
    std::string portname()
    {
        return rfport;
    }
    long long buffer_size()
    {
        return buffer_size_;
    }

private:
    long long bw_hz; // Analog banwidth in Hz
    long long fs_hz; // Baseband sample rate in Hz
    long long lo_hz; // Local oscillator frequency in Hz
    std::string rfport; // Port name
    long long buffer_size_;
};

#endif // STREAM_ARGS_H
