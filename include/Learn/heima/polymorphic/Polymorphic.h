/**
 * @file Polymorphic.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 多态的案例 需要注意的是需要将抽象类的虚析构函数
 * @version 0.1
 * @date 2023-08-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <iostream>

using namespace std;

namespace polymorphic
{
    class Drink // 饮品制作过程
    {
    public:
        Drink()
        {
            cout << "Drink构造函数" << endl;
        }
        virtual ~Drink() // 如果虚析构的话，子类是无法被析构的
        {
            cout << "Drink析构函数" << endl;
        }
        virtual void make() = 0;
    };

    class Tea : public Drink
    {
    public:
        Tea()
        {
            cout << "Tea构造函数" << endl;
        }
        ~Tea()
        {
            cout << "Tea析构函数" << endl;
        }
        void make()
        {
            cout << "茶的制作过程：" << endl;
            cout << "1.煮水" << endl;
            cout << "2.放茶叶" << endl;
            cout << "3.倒入杯中" << endl;
            cout << "4.加柠檬" << endl;
        }
    };

    class Cofe : public Drink
    {
    public:
        Cofe()
        {
            cout << "Cofe构造函数" << endl;
        }
        ~Cofe()
        {
            cout << "Cofe析构函数" << endl;
        }
        void make()
        {
            cout << "咖啡的制作过程：" << endl;
            cout << "1.煮水" << endl;
            cout << "2.将咖啡豆粉碎后冲泡" << endl;
            cout << "3.倒入杯中" << endl;
            cout << "4.加牛奶" << endl;
        }
    };
}