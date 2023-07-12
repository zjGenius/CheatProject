#ifndef FUNCTIMER_H
#define FUNCTIMER_H
#include <chrono>
#include <functional>
#include <ratio>


template <typename R, typename... Args>
struct is_return_void : public std::false_type { };

template <typename... Args>
struct is_return_void<void(Args...)> : public std::true_type { };


template<typename UType = std::milli,typename TR = void,typename Func, typename... BoundArgs>
typename std::enable_if<std::is_same<TR,void>::value>::type FuncElapsedTime(const char *u,Func&& fun, BoundArgs&&... args){
    std::chrono::high_resolution_clock::time_point start_ = std::chrono::high_resolution_clock::now();
    std::invoke(std::forward<Func>(fun), std::forward<BoundArgs>(args)...);
    std::chrono::high_resolution_clock::time_point end_ = std::chrono::high_resolution_clock::now();
    printf("Function HashCode:%llu , elapsed time:%.9f %s \n",
           typeid(fun).hash_code(),
           std::chrono::duration<double, UType>(end_ - start_).count(),
           u);
    printf("void\n");
}

template<typename UType = std::milli,typename TR,typename Func, typename... BoundArgs>
typename std::enable_if<!std::is_same<TR,void>::value>::type FuncElapsedTime(Func&& fun, BoundArgs&&... args){
    std::chrono::high_resolution_clock::time_point start_ = std::chrono::high_resolution_clock::now();
    TR ret = std::invoke(std::forward<Func>(fun), std::forward<BoundArgs>(args)...);
    std::chrono::high_resolution_clock::time_point end_ = std::chrono::high_resolution_clock::now();
    printf("Function HashCode:%llu , elapsed time:%.9f ms \n",
           typeid(fun).hash_code(),
           std::chrono::duration<double, UType>(end_ - start_).count());
    printf("not void\n");
    return ret;
}


//template<typename UType,typename Func, typename... BoundArgs>
//std::enable_if<std::is_void<Func>::value,void>::type FuncElapsedTime(const char * u,Func&& fun, BoundArgs&&... args){
//    std::chrono::high_resolution_clock::time_point start_ = std::chrono::high_resolution_clock::now();
//    std::invoke_result_t<Func, BoundArgs...> ret = std::invoke(std::forward<Func>(fun), std::forward<BoundArgs>(args)...);
//    std::chrono::high_resolution_clock::time_point end_ = std::chrono::high_resolution_clock::now();
//    printf("Function HashCode:%llu , elapsed time:%.9f%s \n",
//           typeid(fun).hash_code(),
//           std::chrono::duration<double, UType>(end_ - start_).count()
//           ,u);
//}



template<typename UType = std::micro,typename Func, typename... BoundArgs>
auto FuncElapsedTimeMicroSecond(Func&& fun, BoundArgs&&... args){
    return FuncElapsedTime<UType>("us",std::forward<Func>(fun),std::forward<BoundArgs>(args)...);
}

template<typename UType = std::milli,typename Func, typename... BoundArgs>
auto FuncElapsedTimeMilliSecond(Func&& fun, BoundArgs&&... args){
    return FuncElapsedTime<UType>("ms",fun,args...);
}

template<typename UType = std::ratio<1>,typename Func, typename... BoundArgs>
auto FuncElapsedTimeSecond(Func&& fun, BoundArgs&&... args){
//    std::enable_if<>
    return FuncElapsedTime<UType>("s",std::forward<Func>(fun),std::forward<BoundArgs>(args)...);
}


template <typename UType, typename Derived>
class FuncRunTimer {
public:
    template <typename Func, typename... BoundArgs>
    FuncRunTimer(Func&& fun, BoundArgs&&... args)
        : start_(std::chrono::high_resolution_clock::now())
    {
        hash_code = typeid(fun).hash_code();
        std::invoke(std::forward<Func>(fun), std::move<BoundArgs>(args)...);
    }
    virtual ~FuncRunTimer()
    {
        end_ = std::chrono::high_resolution_clock::now();
        printf("Function HashCode:%llu , elapsed time:%.9f %s \n",
               hash_code,
               std::chrono::duration<double, UType>(end_ - start_).count(),
               dynamic_cast<Derived*>(this)->Unit());
        //        fflush(stdout);
    }

protected:
    std::chrono::high_resolution_clock::time_point start_;
    std::chrono::high_resolution_clock::time_point end_;
    size_t hash_code;
};

class RunTimerMicroSecond : public FuncRunTimer<std::micro, RunTimerMicroSecond> {
public:
    template <typename Func, typename... BoundArgs>
    RunTimerMicroSecond(Func&& fun, BoundArgs&&... args)
        : FuncRunTimer(fun, args...)
    {
    }
    char* Unit() const { return "us"; }
    ~RunTimerMicroSecond() { }
};

class RunTimerMilliSecond : public FuncRunTimer<std::milli, RunTimerMilliSecond> {
public:
    template <typename Func, typename... BoundArgs>
    RunTimerMilliSecond(Func&& fun, BoundArgs&&... args)
        : FuncRunTimer(fun, args...)
    {
    }
    ~RunTimerMilliSecond() { }
    char* Unit() const { return "ms"; }
};

class RunTimerSecond : public FuncRunTimer<std::ratio<1>, RunTimerSecond> {
public:
    template <typename Func, typename... BoundArgs>
    RunTimerSecond(Func&& fun, BoundArgs&&... args)
        : FuncRunTimer(fun, args...)
    {
    }
    char* Unit() const { return "s"; }
    ~RunTimerSecond() { }
};

#endif // FUNCTIMER_H
