/**
 * @file Composite.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之组合模式
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <string>
#include <list>

class Company
{
protected:
    std::string name;

public:
    Company(std::string name)
    {
        this->name = name;
    }

    virtual void Add(Company *c) = 0;
    virtual void Remove(Company *c) = 0;
    virtual void Display(int dept) = 0;
    virtual void LineOfDuty() = 0;
};

class ConcreateCompany : public Company
{
private:
    std::list<Company *> company_list;

public:
    ConcreateCompany(std::string name) : Company(name){};
    void Add(Company *c)
    {
        company_list.push_back(c);
    }

    void Remove(Company *c)
    {
        company_list.remove(c);
    }

    void Display(int dept)
    {
        for (int i = 0; i < dept; i++)
        {
            printf("-");
        }

        printf("%s\n", name.c_str());

        for (std::list<Company *>::iterator it = company_list.begin(); it != company_list.end(); it++)
            (*it)->Display(dept + 1);
    }

    void LineOfDuty()
    {
        for (std::list<Company *>::iterator it = company_list.begin(); it != company_list.end(); it++)
            (*it)->LineOfDuty();
    }
};

class HRDepartment : public Company
{
public:
    HRDepartment(std::string name) : Company(name){};

    void Add(Company *c)
    {
    }

    void Remove(Company *c)
    {
    }

    void Display(int dept)
    {
        for (int i = 0; i < dept; i++)
        {
            printf("-");
        }
        printf("%s\n", name.c_str());
    }

    void LineOfDuty()
    {
        printf("%s 公司员工培训\n", name.c_str());
    }
};

class FinanceDepartment : public Company
{
public:
    FinanceDepartment(std::string name) : Company(name){};

    void Add(Company *c)
    {
    }

    void Remove(Company *c)
    {
    }

    void Display(int dept)
    {
        for (int i = 0; i < dept; i++)
        {
            printf("-");
        }
        printf("%s\n", name.c_str());
    }

    void LineOfDuty()
    {
        printf("%s 公司财务收支管理\n", name.c_str());
    }
};

#endif // !_COMPOSITE_H_