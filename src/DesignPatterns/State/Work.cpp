#include "Work.h"

Work::Work()
{
    state = new ForenoonState;
    hour = 9;
    finish = false;
}

Work::~Work()
{
    if (state != nullptr)
        delete state;
}

double Work::getHour()
{
    return hour;
}

void Work::setHour(double value)
{
    hour = value;
}

bool Work::getFinish()
{
    return finish;
}

void Work::setFinish(bool value)
{
    finish = value;
}

void Work::setState(State *s)
{
    if (state != nullptr)
        delete state;

    state = s;
}

void Work::writeProgram()
{
    state->writeProgram(this);
}