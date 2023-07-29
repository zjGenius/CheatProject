/**
 * @file Responsibility.h
 * @author your name (you@domain.com)
 * @brief 设计模式之职责链模式
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _RESPONSIBILITY_H_
#define _RESPONSIBILITY_H_

#include <string>

enum RequseType
{
    vacation, // 请假
    raises    // 加薪
};

struct Requesed
{
    int requesedType;        // 类型
    std::string description; // 描述
    int num;                 // 数量
};

class Manager
{
protected:
    std::string name;
    Manager *superManager;

public:
    Manager(std::string n)
    {
        this->name = n;
    }
    void setSuperManager(Manager *m)
    {
        this->superManager = m;
    }

    virtual void RequesedHandle(Requesed re) = 0;
};

// 人事
class HRManager : public Manager
{
public:
    HRManager(std::string n) : Manager(n){};

    void RequesedHandle(Requesed re)
    {
        if (re.requesedType == RequseType::vacation && re.num < 5)
        {
            printf("%s: 批准 %s %d\n", name.c_str(), re.description.c_str(), re.num);
        }
        else
        {
            if (superManager != nullptr)
            {
                superManager->RequesedHandle(re);
            }
        }
    }
};

// 经理
class CommonManager : public Manager
{
public:
    CommonManager(std::string n) : Manager(n){};

    void RequesedHandle(Requesed re)
    {
        if (re.requesedType == RequseType::vacation && re.num <= 10)
        {
            printf("%s: 批准 %s %d\n", name.c_str(), re.description.c_str(), re.num);
        }
        else
        {
            if (superManager != nullptr)
            {
                superManager->RequesedHandle(re);
            }
        }
    }
};

// 经理
class GeneralManager : public Manager
{
public:
    GeneralManager(std::string n) : Manager(n){};

    void RequesedHandle(Requesed re)
    {
        if (re.requesedType == RequseType::vacation)
        {
            printf("%s: 批准 %s %d\n", name.c_str(), re.description.c_str(), re.num);
        }
        else if(re.requesedType == RequseType::raises && re.num <= 500)
        {
            printf("%s: 批准 %s %d\n", name.c_str(), re.description.c_str(), re.num);
        }
        else if(re.requesedType == RequseType::raises && re.num > 500)
        {
            printf("%s: 不批准 %s %d 进步不明显,继续努力\n", name.c_str(), re.description.c_str(), re.num);
        }
    }
};

#endif