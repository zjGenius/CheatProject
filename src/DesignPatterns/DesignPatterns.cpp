#include "DesignPatterns.h"

DesignPatterns::DesignPatterns(/* args */)
{
}

void DesignPatterns::sampleFactory_display()
{
    /***************设计模式之工厂模式 实现加减乘除********************/
    printf("工厂模式\n");
    Operation *oper;
    oper = OperationFactory::createOperate('/');
    oper->setNumberA(10.2);
    oper->setNumberB(2.2);
    double result_num = oper->getResult();

    printf("result_num:%lf\n", result_num);
}

void DesignPatterns::strategy_display()
{
    /***************设计模式之策略模式 商场促销案例********************/
    printf("策略模式\n");
    double result = 0.0;
    int mode = 0;
    double all_money = 0.0;
    CashContext *csuper = new CashContext();
main_function:
    printf("请选择促销模式： \n 0-普通模式 1-返现模式 2-打折模式:  ");
    scanf("%d", &mode);
    switch (mode)
    {
    case MyType::Normal:
    {
        csuper->CreateContext(MyType::Normal);
    }
    break;
    case MyType::Return:
    {
        double amount = 0.0, return_amount = 0.0;
        printf("请输入满减金额与返现金额 (格式:[满减金额,返现金额])  ");
        scanf("%lf,%lf", &amount, &return_amount);
        csuper->SetDiscount(amount, return_amount);
        csuper->CreateContext(MyType::Return);
    }
    break;
    case MyType::Rebate:
    {
        double discount = 0.0;
        printf("请输入折扣 (备注:0.8代表8折)  ");
        scanf("%lf", &discount);
        csuper->SetDiscount(discount);
        csuper->CreateContext(MyType::Rebate);
    }
    break;
    default:
        printf("\n**********输入类型有误!!!\n\n");
        goto main_function;
        break;
    }
    printf("请输入金额: ");
    scanf("%lf", &all_money);
    result = csuper->getResult(all_money);
    printf("最终金额: %.1lf\n", result);
}

void DesignPatterns::decorator_display()
{
    /******************设计模式之装饰模式*************************/
    printf("装饰模式\n");
    // 搭配方案1 (面条6.6 + 鸡蛋0.5 = 7.1元)
    printf("搭配方案1:");
    Food *aaa1 = new FoodNoodle();
    Food *bbb1 = new EggDecorator(aaa1);
    bbb1->myInterface();
    printf("=%f\n\n", bbb1->getPrice());

    // 搭配方案2 （米饭2.5 + 鸡蛋0.5 + 牛肉10 + 火腿5 = 18元）
    printf("搭配方案2:");
    Food *aaa2 = new FoodRice();          // aaa2
    Food *bbb2 = new EggDecorator(aaa2);  // 装饰1（aaa2 + bbb2）
    Food *ccc2 = new BeefDecorator(bbb2); // 装饰2（aaa2 + bbb2 + ccc2）
    Food *ddd2 = new HamDecorator(ccc2);  // 装饰3（aaa2 + bbb2 + ccc2 + ddd2）

    // 此处的ddd2->myInterface()其实是一个链式调用。
    // 链式调用过程：HamDecorator::myInterface() ——> BeefDecorator::myInterface() ——> EggDecorator::myInterface() ——> FoodRice::myInterface()
    // 在每个装饰类的myInterface函数中又加入了具体的装饰操作，所以，装饰顺序与链式调用顺序正好相反。
    ddd2->myInterface();
    printf("=%f\n\n", ddd2->getPrice());

    // 衣服装饰
    Person *per = new Person("xiaoming");

    TShirt *ts = new TShirt();
    Jeans *je = new Jeans();

    ts->Deracte(per);
    je->Deracte(ts);
    je->show();
}

void DesignPatterns::proxy_display()
{
    /******************设计模式之代理模式*************************/
    printf("代理模式\n");
    SchoolGirl *girl = new SchoolGirl("小花");
    Bulb *proxy = new Bulb(girl);
    proxy->sendChocolate();
    proxy->sendFlowers();
    proxy->sendMilk();
}

void DesignPatterns::factoryMethod_display()
{
    /******************设计模式之工厂方法模式*************************/
    printf("工厂方法模式\n");
    LeiFengFactory *factory1 = new StudentFactory();
    L_Student *student = (L_Student *)factory1->createLeiFeng();
    LeiFengFactory *factory2 = new VolunteerFactory();
    L_Volunteer *volunteer = (L_Volunteer *)factory2->createLeiFeng();

    student->buyRice();
    student->sweep();

    volunteer->buyRice();
    volunteer->sweep();
}

void DesignPatterns::prototype_display()
{
    /******************设计模式之原型模式*************************/
    printf("原型模式\n");
    Resume *person = new Resume("小明");
    person->SetPersonalInfo("男", "23");
    person->SetWorkExperience("2022-04-19~", "湖南小金刚");

    Resume person1 = person->clone();
    person1.SetWorkExperience("2022-04-19~2023-01-01", "北京小金刚");

    person->Display();
    person1.Display();
}

void DesignPatterns::template_display()
{
    /******************设计模式之模板模式*************************/
    printf("模板模式\n");
    TestPaper *test1 = new TestPaperA();
    TestPaper *test2 = new TestPaperB();
    printf("考生A\n");
    test1->TestQuestion1();
    test1->TestQuestion2();
    test1->TestQuestion3();
    printf("\n");
    printf("考生B\n");
    test2->TestQuestion1();
    test2->TestQuestion2();
    test2->TestQuestion3();
}

void DesignPatterns::appearance_display()
{
    /******************设计模式之外观模式*************************/
    printf("外观模式\n");
    Facade *facade = new Facade();
    facade->MethodA();
    facade->MethodB();
}

DesignPatterns::~DesignPatterns()
{
}