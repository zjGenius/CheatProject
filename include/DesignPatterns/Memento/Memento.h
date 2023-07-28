/**
 * @file Memento.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之备忘录模式
 * @version 0.1
 * @date 2023-07-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _MEMENTO_H_
#define _MEMENTO_H_

#include <string>

class RoleStateMememto
{
private:
    int stamina;      // 体力
    int aggressivity; // 攻击力
    int defense;      // 防御力
public:
    RoleStateMememto(int s, int a, int d)
    {
        this->stamina = s;
        this->aggressivity = a;
        this->defense = d;
    }

    int getStamina()
    {
        return this->stamina;
    }
    int getAggressivity()
    {
        return this->aggressivity;
    }
    int getDefense()
    {
        return this->defense;
    }
};

class GameCharacters
{
private:
    std::string name;
    int stamina;      // 体力
    int aggressivity; // 攻击力
    int defense;      // 防御力

public:
    GameCharacters(std::string name)
    {
        this->name = name;
    }
    void initState()
    {
        this->stamina = 100;
        this->aggressivity = 100;
        this->defense = 100;
    }
    void Fight()
    {
        this->stamina = 0;
        this->aggressivity = 0;
        this->defense = 0;
    }

    void StateDisplay()
    {
        printf("角色:%s\n体力值:%d\n攻击力:%d\n防御力:%d\n", this->name.c_str(), this->stamina, this->aggressivity, this->defense);
    }

    RoleStateMememto *SaveState()
    {
        return new RoleStateMememto(this->stamina, this->aggressivity, this->defense);
    }

    void RecoveryState(RoleStateMememto *role)
    {
        this->stamina = role->getStamina();
        this->aggressivity = role->getAggressivity();
        this->defense = role->getDefense();
    }
};

class RoleStateCaretaker
{
private:
    RoleStateMememto *role;

public:
    void setRoleStateMememto(RoleStateMememto *role)
    {
        this->role = role;
    }

    RoleStateMememto *getRoleStateMememto()
    {
        return this->role;
    }
};

#endif // !_MEMENTO_H_