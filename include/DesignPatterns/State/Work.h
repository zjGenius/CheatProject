/**
 * @file Work.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之状态模式
 * @version 0.1
 * @date 2023-07-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _DESIGN_WORK_H_
#define _DESIGN_WORK_H_

#include "State.h"

class Work
{
private:
    State *state;
    double hour;
    bool finish;

public:
    Work();
    ~Work();
    double getHour();
    void setHour(double value);
    bool getFinish();
    void setFinish(bool value);
    void setState(State *s);
    void writeProgram();
};

#endif // !_DESIGN_WORK_H_