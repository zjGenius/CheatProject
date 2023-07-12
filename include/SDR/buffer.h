#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <cstdint>

class Buffer
{
public:
    Buffer(int size);

private:
    std::array<int16_t,4096> a;
};

#endif // BUFFER_H
