/**
 * @file Builder.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之建造者模式 
 * 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <list>
#include <string>

// 产品
class Product
{
private:
    std::list<std::string> parts;

public:
    void Add(std::string part)
    {
        parts.push_back(part);
    }

    void Show()
    {
        printf("产品：\n");
        std::list<std::string>::iterator iter;
        for (iter = parts.begin(); iter != parts.end(); iter++)
        {
            printf("%s ", (*iter).c_str());
        }
        printf("\n\n");
    }
};
// 抽象建造者
class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product *getResult() = 0;
};

// 具体的建造者A
class BuilderA : public Builder
{
private:
    Product *pro = new Product();

public:
    void BuildPartA()
    {
        pro->Add("部件A");
    }
    void BuildPartB()
    {
        pro->Add("部件B");
    }
    Product *getResult()
    {
        return pro;
    }
};

// 具体的建造者B
class BuilderB : public Builder
{
private:
    Product *pro = new Product();

public:
    void BuildPartA()
    {
        pro->Add("部件X");
    }
    void BuildPartB()
    {
        pro->Add("部件Y");
    }
    Product *getResult()
    {
        return pro;
    }
};
// 指挥者
class Director
{
public:
    void Construct(Builder *build)
    {
        build->BuildPartA();
        build->BuildPartB();
    }
};

#endif // !_BUILDER_H_