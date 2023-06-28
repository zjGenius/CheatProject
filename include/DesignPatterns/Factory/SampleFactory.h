#ifndef __SAMPLE_FACTORY__
#define __SAMPLE_FACTORY__

#include <stdio.h>
#include <string>

class Operation
{
public:
    virtual double getResult()
    {
        double result_num = 0;
        return result_num;
    }

    void setNumberA(double value)
    {
        _numberA = value;
    }

    void setNumberB(double value)
    {
        _numberB = value;
    }

    double getNumberA()
    {
        return _numberA;
    }
    double getNumberB()
    {
        return _numberB;
    }

private:
    double _numberA = 0;
    double _numberB = 0;
};

class OperationAdd : public Operation
{
public:
    virtual double getResult()
    {
        double result_num = 0;
        result_num = getNumberA() + getNumberB();
        return result_num;
    }
};

class OperationSub : public Operation
{
public:
    double getResult()
    {
        double result_num = 0;
        result_num = getNumberA() - getNumberB();
        return result_num;
    }
};

class OperationMul : public Operation
{
public:
    double getResult()
    {
        double result_num = 0;
        result_num = getNumberA() * getNumberB();
        return result_num;
    }
};

class OperationDiv : public Operation
{
public:
    double getResult()
    {
        double result_num = 0;
        if (getNumberB() == 0)
            throw "除数不能为0 ";
        result_num = getNumberA() / getNumberB();
        return result_num;
    }
};

//工厂类
class OperationFactory
{
public:
    static Operation* createOperate(char operation)
    {
        Operation *oper = nullptr;
        // 根据accsii码
        int i_operation = int(operation);
        switch (i_operation)
        {
        case 43:
            oper = new OperationAdd();
            break;
        case 45:
            oper = new OperationSub();
            break;
        case 42:
            oper = new OperationMul();
            break;
        case 47:
            oper = new OperationDiv();
            break;
        }
        return oper;
    }

private:
};

#endif // __SAMPLE_FACTORY__