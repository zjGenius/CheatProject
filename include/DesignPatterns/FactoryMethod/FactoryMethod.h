/**
 * @file FactoryMethod.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之工厂方法模式 雷锋工厂
 * @version 0.1
 * @date 2023-07-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__

#include <stdio.h>
#include <string>

class LeiFeng
{
public:
    LeiFeng(){};
    virtual void sweep() = 0;
    virtual void wash() = 0;
    virtual void buyRice() = 0;
};

class L_Student : public LeiFeng
{
public:
    L_Student(){};
    void sweep()
    {
        printf("学生-扫地\n");
    }
    void wash()
    {
        printf("学生-洗衣\n");
    }
    void buyRice()
    {
        printf("学生-买米\n");
    }
};

class L_Volunteer : public LeiFeng
{
public:
    L_Volunteer(){};
    void sweep()
    {
        printf("志愿者-扫地\n");
    }
    void wash()
    {
        printf("志愿者-洗衣\n");
    }
    void buyRice()
    {
        printf("志愿者-买米\n");
    }
};

// 雷锋工厂
class LeiFengFactory
{
public:
    LeiFengFactory(){};
    virtual LeiFeng *createLeiFeng() = 0;
};
// 学习雷锋的学生工厂
class StudentFactory : public LeiFengFactory
{
public:
    StudentFactory(){};
    LeiFeng *createLeiFeng()
    {
        return new L_Student();
    }
};
// 学习雷锋的志愿者工厂
class VolunteerFactory : public LeiFengFactory
{
public:
    VolunteerFactory(){};
    LeiFeng *createLeiFeng()
    {
        return new L_Volunteer();
    }
};

#endif // __FACTORY_METHOD_H__