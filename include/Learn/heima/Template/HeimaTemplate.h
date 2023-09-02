/**
 * @file HeimaTemplate.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 模板类的学习
 * @version 0.1
 * @date 2023-08-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <iostream>
using namespace std;

namespace template_heima
{
    class Template
    {
    public:
        Template();
        void templateSwap();
        void templateArraySwap();
        void templateCompare();
    };

    template <class NameType, class AgeType = int> // 类模板可以有默认参数
    class ClassTemplate
    {
    public:
        ClassTemplate(NameType name, AgeType age)
        {
            this->name = name;
            this->age = age;
        }
        void ShowInfo()
        {
            cout << "name:" << this->name << " age:" << this->age << endl;
        }
        NameType name;
        AgeType age;
    };

    
}