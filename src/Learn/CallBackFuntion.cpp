#include "CallBackFuntion.h"

void funcc()
{
    printf("this is funcc\n");
}

CallBackFuntion::CallBackFuntion()
{}

void CallBackFuntion::display()
{
    printf("回调函数\n");
    Program1 pro1;
    pro1.FunA1();
    printf("\n");

    Program2 pro2;
    pro2.FunB1();
    printf("\n");
    pro2.FunB2(funcc);
    printf("\n");
    pro2.FunB2(pro1.FunA3);
    printf("\n");
    pro2.FunB2(std::bind(&Program1::FunA2, &pro1));
}


CallBackFuntion::~CallBackFuntion(){}