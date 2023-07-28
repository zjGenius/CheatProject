/**
 * @file Bridge.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之桥接模式
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _BRIDGE_H_
#define _BRIDGE_H_

#include <stdio.h>

class PhoneSoftware
{
public:
    virtual void Run() = 0;
};

class PhoneGames : public PhoneSoftware
{
public:
    void Run()
    {
        printf("手机游戏\n");
    }
};

class PhoneChat : public PhoneSoftware
{
public:
    void Run()
    {
        printf("聊天软件\n");
    }
};

class Phone
{
protected:
    PhoneSoftware *soft;

public:
    void setPhoneSoftware(PhoneSoftware *soft)
    {
        this->soft = soft;
    }
    virtual void Run() = 0;
};

class PhoneA : public Phone
{
public:
    void Run()
    {
        soft->Run();
    }
};

class PhoneB : public Phone
{
public:
    void Run()
    {
        soft->Run();
    }
};

#endif // !_BRIDGE_H_