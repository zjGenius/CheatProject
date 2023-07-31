/**
 * @file Visitor.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之访问者模式
 * @version 0.1
 * @date 2023-07-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <list>
using namespace std;
class Action; // 类的前向声明
// 人的抽象类
class Visitor_Person
{
public:
    virtual void Accept(Action *visitor) = 0;
    virtual std::string getType() = 0;
};
// 状态的抽象类
class Action
{
public:
    virtual void GetManConclusion(Visitor_Person *concreteElementA) = 0;
    virtual void GetWomanConclusion(Visitor_Person *concreteElementA) = 0;
};

class Man : public Visitor_Person
{
private:
    string person_type = "男人";

public:
    Man()
    {
    }
    void Accept(Action *visitor) override
    {
        visitor->GetManConclusion(this);
    }
    std::string getType()
    {
        return person_type;
    }
};
class Woman : public Visitor_Person
{
private:
    string person_type = "女人";

public:
    Woman()
    {
    }

    void Accept(Action *visitor) override
    {
        visitor->GetWomanConclusion(this);
    }

    std::string getType()
    {
        return person_type;
    }
};

// 具体状态类
class Success : public Action
{
private:
    string type = "成功";

public:
    void GetManConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,背后多半有一个伟大的女人." << endl;
    }
    void GetWomanConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,背后大多有一个不成功的男人." << endl;
    }
};
// 失败
class Failing : public Action
{
private:
    string type = "失败";

public:
    void GetManConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,闷头喝酒，谁也不用劝." << endl;
    }
    void GetWomanConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,眼泪汪汪，谁也劝不了." << endl;
    }
};
// 恋爱
class Amativeness : public Action
{
private:
    string type = "恋爱";

public:
    void GetManConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,凡事不懂也要装懂." << endl;
    }
    void GetWomanConclusion(Visitor_Person *concreteElementA) override
    {
        cout << concreteElementA->getType() << this->type
             << "时,遇事懂也装作不懂." << endl;
    }
};

class ObjectStructure
{
public:
    void Attach(Visitor_Person *element)
    {
        elements.push_back(element);
    }
    void Detach(Visitor_Person *element)
    {
        for (list<Visitor_Person *>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element)
            {
                elements.erase(it);
                break;
            }
        }
    }
    void Display(Action *visitor)
    {
        // 遍历方法
        list<Visitor_Person *>::iterator it;
        for (it = elements.begin(); it != elements.end(); it++)
            (*it)->Accept(visitor);
    }

private:
    list<Visitor_Person *> elements;
};
