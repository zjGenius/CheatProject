/**
 * @file Observer.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之观察者模式
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include "Subject.h"

class Subject;

// 订阅者
class Observer
{
public:
    virtual ~Observer(){};
    virtual void Update(string strEvent) = 0;
};

class StockObserver : public Observer
{
public:
    StockObserver(string NameObserver) : m_NameObserver(NameObserver){};
    virtual void Update(string strEvent)
    {
        cout << m_NameObserver + " get " + strEvent + " call!!" << endl;
    }

private:
    string m_NameObserver;
};

#endif // !_OBSERVER_H_