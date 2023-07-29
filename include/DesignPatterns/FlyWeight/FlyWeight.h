/**
 * @file FlyWeight.h
 * @author your name (you@domain.com)
 * @brief 设计模式之享元模式
 * @version 0.1
 * @date 2023-07-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

#include <string>
#include <map>

class User // 用户
{
private:
    std::string name;

public:
    User(std::string name)
    {
        this->name = name;
    }

    std::string getName()
    {
        return this->name;
    }
};

class WebSite // 网站抽象类
{
public:
    virtual void Use(User *user) = 0;
};

class ConcreateWebSite : public WebSite // 具体网站
{
private:
    std::string web_name;

public:
    ConcreateWebSite(std::string n)
    {
        this->web_name = n;
    }

    void Use(User *u)
    {
        printf("网站分类: %s, 用户: %s\n", this->web_name.c_str(), u->getName().c_str());
    }
};

class WebSiteFactory
{
private:
    std::map<std::string, ConcreateWebSite *> web_map;

public:
    WebSite *getWebSite(std::string web_name)
    {
        if (web_map.find(web_name) == web_map.end())
        {
            web_map[web_name] = new ConcreateWebSite(web_name);
        }
        return (WebSite *)web_map[web_name];
    }

    int getWebSiteCount()
    {
        int num = web_map.size();
        return num;
    }
};

#endif //!_FLYWEIGHT_H_