/**
 * @file HeimaTemplate.cpp
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 * 可以具体化模板调用,解决模板的局限性
 */
#include "HeimaTemplate.h"
#include <iostream>

using namespace template_heima;
using namespace std;

// 交换模板
template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序模板
template <typename T>
void MyArraySwap(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
            MySwap(arr[max], arr[i]);
    }
}

// 打印模板
template <typename T>
void MyPrint(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Template::Template()
{
    cout << "黑马模板学习 Template构造函数" << endl;
}

void Template::templateSwap()
{
    int a = 10, b = 20;
    cout << "int" << endl;
    cout << "a: " << a << " b: " << b << endl;
    MySwap(a, b);
    cout << "a: " << a << " b: " << b << endl;

    float c = 10.5, d = 20.2;
    cout << "float" << endl;
    cout << "a: " << c << " b: " << d << endl;
    MySwap(c, d);
    cout << "a: " << c << " b: " << d << endl;
}

void Template::templateArraySwap()
{
    cout << "int" << endl;
    int arrInt[]{1, 5, 12, 8, 45, 3, 4, 5, 2, 36, 4};
    int arrInt_len = sizeof(arrInt) / sizeof(int);

    MyPrint(arrInt, arrInt_len);
    MyArraySwap(arrInt, arrInt_len);
    MyPrint(arrInt, arrInt_len);

    cout << "char" << endl;
    char arrChar[]{'a', 'b', 'd', 'c', 'f'};
    int arrChar_len = sizeof(arrChar) / sizeof(char);

    MyPrint(arrChar, arrChar_len);
    MyArraySwap(arrChar, arrChar_len);
    MyPrint(arrChar, arrChar_len);
}

class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
    string mName;
    int mAge;
};

template <typename T>
bool Compare(T &a, T &b)
{
    if (a == b)
        return true;
    else
        return false;
}

// 具体化模板调用,解决模板的局限性
template <>
bool Compare(Person &a, Person &b)
{
    if (a.mName == b.mName && a.mAge == b.mAge)
        return true;
    else
        return false;
}

void Template::templateCompare()
{
    Person p1("Tom", 10);
    Person p2("Tom", 11);
    if (Compare(p1, p2))
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;
}
