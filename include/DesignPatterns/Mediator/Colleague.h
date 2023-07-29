/**
 * @file Colleague.h
 * @author your name (you@domain.com)
 * @brief 设计模式之中介者模式
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <string>
#include "Mediator.h"
class UnitedNations;

class Country // 具体类
{
protected:
    UnitedNations *meditor;

public:
    Country(UnitedNations *m)
    {
        this->meditor = m;
    }
};

class USA : public Country
{
public:
    USA(UnitedNations *m) : Country(m){};

    void Declare(std::string message)
    {
        meditor->Declare(message, this);
    }

    void getMessage(std::string massage)
    {
        printf("美国获得对方消息：%s\n", massage.c_str());
    }
};

class Iraq : public Country
{
public:
    Iraq(UnitedNations *m) : Country(m){};

    void Declare(std::string message)
    {
        meditor->Declare(message, this);
    }

    void getMessage(std::string massage)
    {
        printf("伊拉克获得对方消息：%s\n", massage.c_str());
    }
};

class UnitedNationsSecurityCouncil : public UnitedNations
{
private:
    USA *usa;
    Iraq *iraq;

public:
    void setUSA(USA *u)
    {
        this->usa = u;
    }
    void setIraq(Iraq *i)
    {
        this->iraq = i;
    }

    void Declare(std::string message, Country *c)
    {
        if (c == this->usa)
        {
            iraq->getMessage(message);
        }
        else if (c == this->iraq)
        {
            usa->getMessage(message);
        }
    }
};