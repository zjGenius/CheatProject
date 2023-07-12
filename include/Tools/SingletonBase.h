
#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H
#include <type_traits>
#include <memory>
#define SINGLETON_OBJECT(obj) public:obj(token_){};
template <typename Derive>
class SingletonBase {
public:
    static Derive& Instance() noexcept(std::is_nothrow_constructible<Derive>::value)
    {
        static const std::unique_ptr<Derive> instance{new Derive{token_{}}};
        //        static Derive instance{token_()};
        return *instance;
    }
    virtual ~SingletonBase() noexcept = default;
    SingletonBase(const SingletonBase&) = delete;
    //    SingletonBase(const SingletonBase&&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;
    //    SingletonBase& operator=(const SingletonBase&&) = delete;

protected:
    struct token_{};
    SingletonBase()
    {
    }
};

#endif // SINGLETONBASE_H
