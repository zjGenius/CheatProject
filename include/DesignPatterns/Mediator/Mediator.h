/**
 * @file Mediator.h
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
#include "Colleague.h"
class Country;

class UnitedNations // 中介
{
public:
    virtual void Declare(std::string message, Country *con) = 0;
};
