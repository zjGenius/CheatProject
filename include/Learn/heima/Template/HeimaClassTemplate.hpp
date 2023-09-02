/**
 * @file HeimaClassTemplate.hpp
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 类模板构造函数与成员函数 类外实现
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class HeimaClassTemplate
{
private:
    T1 name;
    T2 age;

public:
    HeimaClassTemplate(T1 t1, T2 t2);
    void ShowInfo();
};

template <class T1, class T2>
HeimaClassTemplate<T1, T2>::HeimaClassTemplate(T1 t1, T2 t2)
{
    cout << "HeimaClassTemplate构造函数" << endl;
    cout << "解决方法一,在一个.hpp文件内申明与实现,这是常用的方法" << endl;
    cout << "另外一种方法是包含.cpp,但是这个方法不常用" << endl;
    this->name = t1;
    this->age = t2;
}

template <class T1, class T2>
void HeimaClassTemplate<T1, T2>::ShowInfo()
{
    cout << "name:" << this->name << " age:" << this->age << endl;
}
