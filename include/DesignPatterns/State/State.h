/**
 * @file State.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 设计模式之状态模式
 * @version 0.1
 * @date 2023-07-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _DESIGN_STATE_H_
#define _DESIGN_STATE_H_
class Work;

class State
{
public:
    State(){};
    virtual void writeProgram(Work *w){};
};
// 上午
class ForenoonState : public State
{
public:
    void writeProgram(Work *w);
};
// 中午
class NoonState : public State
{
public:
    void writeProgram(Work *w);
};
// 下午
class AfternoonState : public State
{
public:
    void writeProgram(Work *w);
};
// 晚上
class EveningState : public State
{
public:
    void writeProgram(Work *w);
};
// 睡觉
class SleepingState : public State
{
public:
    void writeProgram(Work *w);
};
// 休息
class RestState : public State
{
public:
    void writeProgram(Work *w);
};

#endif // !_DESIGN_STATE_H_