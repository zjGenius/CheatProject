/**
 * @file Command.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之命令模式
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>
#include <list>

class Cooking
{
public:
    void CookBeaf()
    {
        printf("烤牛肉串\n");
    }
    void CookChicken()
    {
        printf("烤鸡腿\n");
    }
};

class Command
{
protected:
    Cooking *cook;

public:
    Command(Cooking *c)
    {
        this->cook = c;
    }

    virtual void ExecuteCommand() = 0;
};

class BeafCommand : public Command
{
public:
    BeafCommand(Cooking *c) : Command(c){};

    void ExecuteCommand()
    {
        cook->CookBeaf();
    }
};

class ChickenCommand : public Command
{
public:
    ChickenCommand(Cooking *c) : Command(c){};

    void ExecuteCommand()
    {
        cook->CookChicken();
    }
};

class Waiter
{
private:
    std::list<Command *> orders;

public:
    void SetOrder(Command *command)
    {
        bool flag = typeid(*command) == typeid(BeafCommand);
        // printf("flag:%d\n", flag);
        if (flag)
        {
            printf("牛肉串没了\n");
        }
        else
        {
            orders.push_back(command);
        }
    }

    void CancelOrder(Command *c)
    {
        orders.remove(c);
        printf("移除\n");
    }

    void Notify()
    {
        for (std::list<Command *>::iterator it = orders.begin(); it != orders.end(); it++)
        {
            (*it)->ExecuteCommand();
        }
    }
};

#endif // !COMMAND_H__