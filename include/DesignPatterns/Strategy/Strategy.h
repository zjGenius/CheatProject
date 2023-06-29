#ifndef __Strategy__
#define __Strategy__

#include <stdio.h>
#include <iostream>
#include <math.h>

enum MyType
{
    Normal, // 正常收费
    Return, // 返现
    Rebate  // 打折
};

class CrashSuper
{
public:
    virtual double accepetCash(double money)
    {
        double result = 0.0;
        return result;
    }
};

class CrashNormal : CrashSuper
{
public:
    double accepetCash(double money)
    {
        double result = 0.0;
        result = money;
        return result;
    }
};

// 返现
class CrashReturn : CrashSuper
{
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;

public:
    CrashReturn(double moneyCondition, double moneyReturn)
    {
        this->moneyCondition = moneyCondition;
        this->moneyReturn = moneyReturn;
    }

    double accepetCash(double money)
    {
        double result = 0.0;
        result = money;
        if (money >= this->moneyCondition)
            result = money - floor(money / this->moneyCondition) * this->moneyReturn;

        return result;
    }
};

// 打折
class CrashRebate : CrashSuper
{
private:
    double moneyRebate = 1.0;

public:
    CrashRebate(double moneyRebate)
    {
        this->moneyRebate = moneyRebate;
    }

    double accepetCash(double money)
    {
        double result = 0.0;
        result = money * this->moneyRebate;
        return result;
    }
};

class CashContext
{
private:
    CrashSuper *cs = nullptr;
    double discount = 1.0;
    double amount = 0.0;
    double return_amount = 0.0;

public:
    // CashContext(char type)
    // {
    //     // 根据accsii码
    //     int i_type = int(type);
    //     switch (i_type)
    //     {
    //     case MyType::Normal:
    //     {
    //         CrashNormal *cs_0 = new CrashNormal();
    //         this->cs = (CrashSuper *)cs_0;
    //     }
    //     break;
    //     case MyType::Return:
    //     {
    //         CrashReturn *cs_1 = new CrashReturn(this->amount, this->return_amount);
    //         this->cs = (CrashSuper *)cs_1;
    //     }
    //     break;
    //     case MyType::Rebate:
    //     {
    //         CrashRebate *cs_2 = new CrashRebate(this->discount);
    //         this->cs = (CrashSuper *)cs_2;
    //     }
    //     break;
    //     default:
    //         break;
    //     }
    // }
    CashContext(){}
    /**
     * @brief 设置返现优惠参数
     * 
     * @param discount 折扣
     */
    void SetDiscount(double discount)
    {
        this->discount = discount;
    }
    /**
     * @brief 设置返现优惠参数
     * 
     * @param amount        满减金额 
     * @param return_amount 返现金额
     */
    void SetDiscount(double amount, double return_amount)
    {
        this->amount = amount;
        this->return_amount = return_amount;
    }

    /**
     * @brief 获取结果
     * 
     * @param money 
     * @return double 
     */
    double getResult(double money)
    {
        return cs->accepetCash(money);
    }

    /**
     * @brief 创建
     * 
     * @param type 
     */
    void CreateContext(int type)
    {
        switch (type)
        {
        case MyType::Normal:
        {
            CrashNormal *cs_0 = new CrashNormal();
            this->cs = (CrashSuper *)cs_0;
        }
        break;
        case MyType::Return:
        {
            CrashReturn *cs_1 = new CrashReturn(this->amount, this->return_amount);
            this->cs = (CrashSuper *)cs_1;
        }
        break;
        case MyType::Rebate:
        {
            CrashRebate *cs_2 = new CrashRebate(this->discount);
            this->cs = (CrashSuper *)cs_2;
        }
        break;
        default:
            break;
        }
    }
};

#endif // __Strategy__