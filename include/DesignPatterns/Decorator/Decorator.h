/**
 * @file Decorator.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 装饰模式
 * @version 0.1
 * @date 2023-7-6
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <stdio.h>
#include <string>

class Food
{
public:
	Food(){}
	virtual ~Food(){}

	virtual void myInterface() = 0; // 为后续的各种装饰操作提供一个统一的接口
	void setPrice(double s) { mPrice = s; }
	double getPrice() { return mPrice; }

private:
	double mPrice;    // 食物价格
};

// 米饭类
class FoodRice :public Food
{
public:
	FoodRice() {
		setPrice(2.5);
	}

	~FoodRice() {}

	virtual void myInterface()
	{
        printf("米饭");
	}
};

// 面条类
class FoodNoodle :public Food
{
public:
	FoodNoodle()
	{
		setPrice(6.6);
	}

	~FoodNoodle() {}

	virtual void myInterface()
	{
        printf("面条");
	}
};

class Decorator :public Food
{
public:
	Decorator(Food* food)
	{
		mFood = food;
	}

	virtual ~Decorator(){}

	virtual void myInterface()
	{
		this->mFood->myInterface();
	}

	Food* getFood()              // 父类的私有成员mFood 在子类中调用get()方法获取
	{
		return this->mFood;
	}

	void setFood(Food* food)     // 父类的私有成员mFood 在子类中调用set()方法设置
	{
		this->mFood = food;
	}

private:
	Food* mFood = nullptr;  // 关键：装饰类中维护一个被装饰对象的基类指针
};
// 装饰类（加鸡蛋）
class EggDecorator :public Decorator
{
public:
	EggDecorator(Food* food): Decorator(food) // 通过装饰类的构造函数传入被装饰对象
	{
		this->setFood(food);
	}

	virtual ~EggDecorator(){}

	virtual void myInterface()
	{
		this->getFood()->myInterface(); // getFood()返回的是从构造函数中传入的被装饰对象，故此处调用的是被装饰对象的myInterface()函数
		doDecorator();                  // 进行装饰操作
	}

private:
	// 装饰操作：加鸡蛋并重新计算价格
	void doDecorator()
	{
        printf("+鸡蛋");
		setPrice(this->getFood()->getPrice() + 0.5); // this->getFood()->getPrice() 返回的是加鸡蛋之前的价格
	}                                                // this->setPrice(double) 设置的是加入鸡蛋后的价格
};


// 装饰类（加牛肉）
class BeefDecorator :public Decorator
{
public:
	BeefDecorator(Food* food) : Decorator(food)
	{
		this->setFood(food);
	}

	virtual ~BeefDecorator() {}

	virtual void myInterface()
	{
		this->getFood()->myInterface();
		doDecorator();
	}

private:
	void doDecorator()
	{
        printf("+牛肉");
		setPrice(this->getFood()->getPrice() + 10);
	}
};


// 装饰类（加火腿）
class HamDecorator :public Decorator
{
public:
	HamDecorator(Food* food) : Decorator(food)
	{
		this->setFood(food);
	}

	virtual ~HamDecorator() {}

	virtual void myInterface()
	{
		this->getFood()->myInterface();
		doDecorator();
	}

private:
	void doDecorator()
	{
        printf("+火腿");
		setPrice(this->getFood()->getPrice() + 5);
	}
};


#endif // __DECORATOR_H__