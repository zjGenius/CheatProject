/**
 * @file Operator.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 运算符重载的练习
 * @version 0.1
 * @date 2023-08-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

#pragma once

namespace Operator
{
    class Person
    {
        friend ostream &operator<<(ostream &out, Person &p)
        {
            out << "numA:" << p.num_A << " numB:" << p.num_B;
            return out;
        }

        friend Person
        operator+(Person &p1, Person &p2)
        {
            Person per;
            per.setNumA(p1.getNumA() + p2.getNumA());
            per.setNumB(p1.getNumB() + p2.getNumB());
            return per;
        }

    private:
        int num_A;
        int num_B;

    public:
        void setNumA(int num);
        void setNumB(int num);
        int getNumA();
        int getNumB();
    };

    class MyInteger
    {
        friend ostream &operator<<(ostream &out, MyInteger myInt)
        {
            out << myInt.num;
            return out;
        }

    private:
        int num;

    public:
        MyInteger() { num = 0; }

        // 前置++
        MyInteger &operator++()
        {
            num++;
            return *this;
        }

        // 后置++
        MyInteger operator++(int)
        {
            MyInteger temp = *this;
            num++;
            return temp;
        }
    };

}
