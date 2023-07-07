/**
 * @file Proxy.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 代理模式 讲述电灯泡帮男孩追女孩的故事
 * @version 0.1
 * @date 2023-07-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _PROXY_H_
#define _PROXY_H_

#include <stdio.h>
#include <string>

using namespace std;

// 被追求者
class SchoolGirl
{
private:
    string name;

public:
    SchoolGirl(){};
    SchoolGirl(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
};

// 同样的行为
class Behavior
{
public:
    virtual void sendFlowers() = 0;
    virtual void sendChocolate() = 0;
    virtual void sendMilk() = 0;
};

// 追求者
class Boy : public Behavior
{
private:
    SchoolGirl *girl;

public:
    Boy(SchoolGirl *girl)
    {
        this->girl = girl;
    }
    void sendFlowers()
    {
        printf("%s 送你花\n", girl->getName().c_str());
    }
    void sendChocolate()
    {
        printf("%s 送你巧克力\n", girl->getName().c_str());
    }
    void sendMilk()
    {
        printf("%s 送你牛奶\n", girl->getName().c_str());
    }
};

// 究极电灯泡
class Bulb : public Behavior
{
private:
    Boy *boy;

public:
    Bulb(SchoolGirl *girl)
    {
        if (boy == nullptr)
            boy = new Boy(girl);
    }
    void sendFlowers()
    {
        boy->sendFlowers();
    }
    void sendChocolate()
    {
        boy->sendChocolate();
    }
    void sendMilk()
    {
        boy->sendMilk();
    }
};

#endif // !_PROXY_H_