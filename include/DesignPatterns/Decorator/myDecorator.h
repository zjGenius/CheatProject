/**
 * @file Decorator.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 装饰模式
 * @version 0.1
 * @date 2023-7-6
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __MYDECORATOR_H__
#define __MYDECORATOR_H__

#include <stdio.h>
#include <string>

using namespace std;

class Person
{
private:
    string myname;

public:
    Person(){};
    Person(string name)
    {
        myname = name;
    }
    virtual void show()
    {
        printf("装饰的%s\n", myname.c_str());
    }
};

class Finary : public Person
{
protected:
    Person *pr;

public:
    Finary(){};
    void Deracte(Person *person)
    {
        pr = person;
    }
    void show()
    {
        if (pr != nullptr)
        {
            pr->show();
        }
    }
};

class TShirt : public Finary
{
public:
    TShirt(){};
    void show()
    {
        printf("白T恤 ");
        Finary::show();
    }
};

class Jeans : public Finary
{
public:
    Jeans(){};
    void show()
    {
        printf("牛仔裤 ");
        Finary::show();
    }
};

#endif // __MYDECORATOR_H__