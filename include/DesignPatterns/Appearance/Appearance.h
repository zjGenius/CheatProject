/**
 * @file Appearance.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之外观模式  
 * 为子系统中的一组接口提供一个一致的页面，此模式定义了一个高层接口，
 * 这个接口使得这一子系统更加容易使用。
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _APPEARANCE_H_
#define _APPEARANCE_H_

#include <stdio.h>

class SubSystemOne
{
public:
    void MethodOne()
    {
        printf("子系统方法一\n");
    }
};
class SubSystemTwo
{
public:
    void MethodTwo()
    {
        printf("子系统方法二\n");
    }
};
class SubSystemThree
{
public:
    void MethodThree()
    {
        printf("子系统方法三\n");
    }
};
class SubSystemFour
{
public:
    void MethodFour()
    {
        printf("子系统方法四\n");
    }
};

class Facade
{
private:
    SubSystemOne *one;
    SubSystemTwo *two;
    SubSystemThree *three;
    SubSystemFour *four;

public:
    Facade()
    {
        one = new SubSystemOne();
        two = new SubSystemTwo();
        three = new SubSystemThree();
        four = new SubSystemFour();
    }

    void MethodA()
    {
        printf("\n方法组一\n");
        one->MethodOne();
        two->MethodTwo();
        four->MethodFour();
    }

    void MethodB()
    {
        printf("\n方法组二\n");
        two->MethodTwo();
        three->MethodThree();
    }
};

#endif // !_APPEARANCE_H_