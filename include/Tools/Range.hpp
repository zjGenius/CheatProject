#ifndef RANGE_HPP
#define RANGE_HPP
#include <functional>
#include <ostream>
template <typename _Type>
struct Range {
    struct RangeHash {
        [[nodiscard]] std::size_t operator()(const Range<_Type>& key) const noexcept
        {
            auto h = std::hash<_Type>();
            return h(key.left()) ^ h(key.right());
        }
    };

    Range()
        : left_(0)
        , right_(0) {};
    Range(_Type l, _Type r)
        : left_(l)
        , right_(r)
    {
        assert(left_ <= right_);
    };
    void setRange(_Type l, _Type r)
    {
        left_ = l;
        right_ = r;
        assert(left_ <= right_);
    }
    void setRangeByDiff(_Type mid, _Type diff)
    {
        left_ = mid - diff;
        right_ = mid + diff;
        assert(left_ <= right_);
    }
    template <typename _Ty>
    inline bool in(_Ty v) const
    {
        return left_ <= v && v <= right_;
    }
//    template <typename _Ty>
//    bool operator()(const _Ty& v)
//    {
//        return in<_Ty>(v);
//    }

    bool operator==(const Range<_Type>& rhs) const
    {
        return this->left_ == rhs.left_ && this->right_ == rhs.right_;
    }
    bool operator!=(const Range<_Type>& rhs) const
    {
        return !((*this) == rhs);
    }

    _Type left() const
    {
        return this->left_;
    }
    _Type right() const
    {
        return this->right_;
    }

    //    friend bool operator==(Range const& lhs, Range const& rhs)
    //    {
    //        return lhs.left_ == rhs.left_ && lhs.right_ == rhs.right_;
    //    }
    template <typename _Ty>
    Range<_Ty> cast()
    {
        return Range<_Ty>(this->left_, this->right_);
    }

    friend std::ostream& operator<<(std::ostream& os, const Range& v)
    {
        return (os << "[" << v.left_ << "," << v.right_ << "]");
    }

protected:
    _Type left_;
    _Type right_;
};

#endif // RANGE_HPP
