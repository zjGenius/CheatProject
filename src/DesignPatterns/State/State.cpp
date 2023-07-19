#include <iostream>

#include "State.h"
#include "Work.h"

using namespace std;

void ForenoonState::writeProgram(Work *w)
{
    if (w->getHour() < 12)
        cout << "当前时间:" << w->getHour() << ", 上午精神百倍" << endl;
    else
    {
        w->setState(new NoonState);
        w->writeProgram();
    }
}

void NoonState::writeProgram(Work *w)
{
    if (w->getHour() < 13)
    {
        cout << "当前时间:" << w->getHour() << ", 中午犯困" << endl;
    }
    else
    {
        w->setState(new AfternoonState);
        w->writeProgram();
    }
}

void AfternoonState::writeProgram(Work *w)
{
    if (w->getHour() < 17)
    {
        cout << "当前时间:" << w->getHour() << ", 下午快下班了" << endl;
    }
    else
    {
        w->setState(new EveningState);
        w->writeProgram();
    }
}

void EveningState::writeProgram(Work *w)
{
    if (w->getFinish())
    {
        w->setState(new RestState);
        w->writeProgram();
    }
    else
    {
        if (w->getHour() < 21)
        {
            cout << "当前时间:" << w->getHour() << ", 苦逼加班啊" << endl;
        }
        else
        {
            w->setState(new SleepingState);
            w->writeProgram();
        }
    }
}

void SleepingState::writeProgram(Work *w)
{
    cout << "当前时间:" << w->getHour() << ", 睡觉了" << endl;
}

void RestState::writeProgram(Work *w)
{
    cout << "当前时间:" << w->getHour() << ", 下班休息了" << endl;
}