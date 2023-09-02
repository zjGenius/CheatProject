/**
 * @file HeimaFriendTemplate.hpp
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 友元函数类内实现与类外实现
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 * 建议类内实现，比较简单，编译器可以直接识别
 */
#pragma once
#include <iostream>
using namespace std;

template <class T1, class T2>
class HeimaFriendTemplate;

template <class T1, class T2>
void printfOutside(HeimaFriendTemplate<T1, T2> p)
{
    cout << "类外实现 姓名:" << p.name << " 年龄:" << p.age << endl;
}

template <class T1, class T2>
class HeimaFriendTemplate
{
    // 友元函数类内实现
    friend void printfInside(HeimaFriendTemplate<T1, T2> p)
    {
        cout << "类内实现 姓名:" << p.name << " 年龄:" << p.age << endl;
    }

    // 友元函数类外实现
    friend void printfOutside<>(HeimaFriendTemplate<T1, T2> p);

private:
    T1 name;
    T2 age;

public:
    HeimaFriendTemplate(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
};
