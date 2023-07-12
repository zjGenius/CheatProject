#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace Tools {
//bool isInRange()
    inline namespace literals {
        [[nodiscard]] constexpr  long long operator"" _HZ(unsigned long long value)noexcept{
            return value;
        }
        [[nodiscard]] constexpr  long long operator"" _BHZ(unsigned long long value)noexcept{
            return value * 100;
        }
        [[nodiscard]] constexpr  long long operator"" _KHZ(unsigned long long value)noexcept{
            return value * 1000;
        }
        [[nodiscard]] constexpr  long long operator"" _MHZ(unsigned long long value)noexcept{
            return value * 1000000;
        }
    }

    [[nodiscard]] inline constexpr  long long BHZ(double value)noexcept{
        return (( long long)(value * 100.0 + .5));
    }
    [[nodiscard]] inline constexpr  long long KHZ(double value)noexcept{
        return (( long long)(value * 1000.0 + .5));
    }
    [[nodiscard]] inline constexpr  long long MHZ(double value)noexcept{
        return (( long long)(value * 1000000.0 + .5));
    };
    [[nodiscard]] inline constexpr  long long GHZ(double value)noexcept{
        return (( long long)(value * 1000000000.0 + .5));
    };

}

#endif // TOOLS_H
