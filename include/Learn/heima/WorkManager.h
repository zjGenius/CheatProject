/**
 * @file WorkManager.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 职工管理系统，遇到点问题，没往下写了
 * @version 0.1
 * @date 2023-08-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <iostream>

using namespace std;

namespace workManagerSpace
{
    class Woker
    {
    private:
        int mId;
        string mName;
        int mDid;

    public:
        virtual void showInfo() = 0;
        virtual string getDepartName() = 0;
    };

    class Employee : public Woker
    {
    private:
        int mId;
        string mName;
        int mDid;

    public:
        Employee(int id, string name, int did);
        void showInfo();
        string getDepartName();
    };
    class Manager : public Woker
    {
    private:
        int mId;
        string mName;
        int mDid;

    public:
        Manager(int id, string name, int did);
        void showInfo();
        string getDepartName();
    };
    class Boss : public Woker
    {
    private:
        int mId;
        string mName;
        int mDid;

    public:
        Boss(int id, string name, int did);
        void showInfo();
        string getDepartName();
    };

    class WorkManager
    {
    private:
        void showMenu();

    public:
        WorkManager(/* args */);
        ~WorkManager();

        void startSystem();
    };

}