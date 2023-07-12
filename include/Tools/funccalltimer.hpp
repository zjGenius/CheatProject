#ifndef FUNCCALLTIMER_HPP
#define FUNCCALLTIMER_HPP

#include <atomic>
#include <functional>
#include <iostream>
#include <thread>

class FuncCallTimer {
public:
    explicit FuncCallTimer()
    {
        stop();
    }
    template <typename Func, typename... BoundArgs>
    void startTimer(int msec, Func&& func, BoundArgs&&... args)
    {
        if (running_ == true) {
            stop();
        }
        running_ = true;
        thread_ = std::thread(&FuncCallTimer::run_<Func, BoundArgs...>, this,
                              msec,
                              std::forward<Func>(func),
                              std::forward<BoundArgs>(args)...);
        thread_.detach();
    }
    template <typename Func, typename... BoundArgs>
    void startTimer(int msec, Func&& func, BoundArgs&... args)
    {
        if (running_ == true) {
            stop();
        }
        running_ = true;
        thread_ = std::thread(&FuncCallTimer::run_<Func, BoundArgs...>, this,
                              msec,
                              std::forward<Func>(func),
                              std::forward<BoundArgs>(args)...);
        thread_.detach();
    }

    void stop()
    {
        running_ = false;
    }

private:
    template <typename Func, typename... BoundArgs>
    void run_(int msec, Func&& func, BoundArgs&&... args)
    {
        while (running_ == true) {
            std::invoke(std::forward<Func>(func), std::forward<BoundArgs>(args)...);
            std::this_thread::sleep_for(std::chrono::milliseconds(msec));
        }
    }

private:
    std::thread thread_;
    std::atomic_bool running_;
};

#endif // FUNCCALLTIMER_HPP
