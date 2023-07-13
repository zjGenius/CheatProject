/**
 * @file Template.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之模板模式
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include <string>

class TestPaper
{
public:
    void TestQuestion1()
    {
        printf("题目1 ");
        printf("答案：%s\n", Answer1().c_str());
    }

    void TestQuestion2()
    {
        printf("题目2 ");
        printf("答案：%s\n", Answer2().c_str());
    }

    void TestQuestion3()
    {
        printf("题目3 ");
        printf("答案：%s\n", Answer3().c_str());
    }

protected:
    virtual std::string Answer1()
    {
        return "";
    }
    virtual std::string Answer2()
    {
        return "";
    }
    virtual std::string Answer3()
    {
        return "";
    }
};

class TestPaperA : public TestPaper
{
protected:
    std::string Answer1()
    {
        return "a";
    }
    std::string Answer2()
    {
        return "b";
    }
    std::string Answer3()
    {
        return "c";
    }
};

class TestPaperB : public TestPaper
{
protected:
    std::string Answer1()
    {
        return "c";
    }
    std::string Answer2()
    {
        return "b";
    }
    std::string Answer3()
    {
        return "a";
    }
};

#endif // !_TEMPLATE_H_