#ifndef _DESIGN_GUANCHAZHE_HPP_
#define _DESIGN_GUANCHAZHE_HPP_

#include <iostream>
#include <list>
#include <string>

class Test_Viewer;

class Test_Observer
{
protected:
    std::string m_name;
    Test_Viewer *m_viewer;

public:
    Test_Observer(std::string name, Test_Viewer *viewer)
    {
        m_name = name;
        m_viewer = viewer;
    }
    virtual void notify() = 0;
};

class Test_NBA_Observer : public Test_Observer
{
public:
    Test_NBA_Observer(std::string name, Test_Viewer *viewer) : Test_Observer(name, viewer) {}
    void notify();
};

class Test_Stock_Observer : public Test_Observer
{
public:
    Test_Stock_Observer(std::string name, Test_Viewer *viewer) : Test_Observer(name, viewer) {}
    void notify();
};

class Test_Viewer
{
private:
    std::list<Test_Observer *> observer_list;

public:
    std::string text;
    void addObserver(Test_Observer *obj)
    {
        observer_list.push_back(obj);
    }

    void notify()
    {
        for (auto iter = observer_list.begin(); iter != observer_list.end(); iter++)
        {
            (*iter)->notify();
        }
    }
};


void Test_NBA_Observer::notify()
{
    std::cout << m_name << " 收到消息：" << m_viewer->text << std::endl;
    if(m_viewer->text == "老板来了!")
    {
        std::cout << "马上关闭NBA直播，开始工作!" << std::endl;
    }
}

void Test_Stock_Observer::notify()
{
    std::cout << m_name << " 收到消息：" << m_viewer->text << std::endl;
    if(m_viewer->text == "老板来了!")
    {
        std::cout << "马上关闭股票软件，开始工作!" << std::endl;
    }
}

#endif // !_DESIGN_GUANCHAZHE_HPP_