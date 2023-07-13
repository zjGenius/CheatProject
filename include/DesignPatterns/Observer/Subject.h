/**
 * @file Subject.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之观察者模式
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <string>
#include <list>
#include "Observer.h"

// 发布者
class Subject
{
public:
    virtual void addObserver(Observer *ob) = 0;
    virtual void delObserver(Observer *ob) = 0;
    virtual int notify(string strEvent) = 0;
};

class Boss : public Subject
{
public:
    virtual void addObserver(Observer *ob)
    {
        m_listObserver.push_back(ob);
    }
    virtual void delObserver(Observer *ob)
    {
        m_listObserver.remove(ob);
    }
    virtual int notify(string strEvent)
    {
        if (!m_listObserver.empty())
        {
            list<Observer *>::iterator itObserver;
            for (itObserver = m_listObserver.begin(); itObserver != m_listObserver.end(); ++itObserver)
            {
                Observer *pObserver = *itObserver;
                pObserver->Update(strEvent);
            }
        }
        return m_listObserver.size();
    }

    void Come()
    {
        cout << "Boss : hello boys ,I come in" << endl;
        notify("Boss come");
    }
    void Leave()
    {
        cout << "Boss : Good bye boys" << endl;
        notify("Boss leave");
    }

private:
    list<Observer *> m_listObserver;
};

#endif // !_SUBJECT_H_