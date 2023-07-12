/**
 * @file Prototype.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之原型模式
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include <string>

class Resume
{
private:
    std::string name;
    std::string sex;
    std::string age;
    std::string timeArea;
    std::string company;

public:
    Resume(std::string name)
    {
        this->name = name;
    }
    // 设置个人信息
    void SetPersonalInfo(std::string sex, std::string age)
    {
        this->sex = sex;
        this->age = age;
    }
    // 设置工作经历
    void SetWorkExperience(std::string timeArea, std::string company)
    {
        this->timeArea = timeArea;
        this->company = company;
    }
    // 显示
    void Display()
    {
        printf("%s %s %s 工作经历: %s %s\n", this->name.c_str(), this->sex.c_str(), this->age.c_str(), this->timeArea.c_str(), this->company.c_str());
    }

    // 浅拷贝 返回的是一个对象，不是对象的地址
    Resume clone()
    {
        return *(Resume *)this;
    }

    // 深拷贝 返回的是一个对象地址
    Resume* copy()
    {
        return this;
    }
};

#endif // _PROTOTYPE_H_