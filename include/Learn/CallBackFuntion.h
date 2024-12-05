/**
 * @file CallBackFuntion.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief c++中回调函数的使用
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _CALLBACK_FUNCTION_
#define _CALLBACK_FUNCTION_

#include <iostream>
#include <functional>

class Program1
{
public:
    void FunA1() { printf("this is Program1.FunA1\n"); }
    void FunA2() { printf("this is Program1.FunA2\n"); }
    static void FunA3() { printf("this is Program1.FunA3\n"); }
};

class Program2
{
private:
    typedef std::function<void()> CallBackFunc;

public:
    void FunB1() { printf("this is Program2.FunB1\n"); }
    void FunB2(CallBackFunc func)
    {
        printf("this is Program2.FunB2\n");
        func();
    }
};

class CallBackFuntion
{
private:
    /* data */
public:
    CallBackFuntion(/* args */);
    ~CallBackFuntion();

    void display();
};

#endif // !_CALLBACK_FUNCTION_