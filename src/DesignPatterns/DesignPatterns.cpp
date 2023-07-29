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

void DesignPatterns::builder_display()
{
    /******************设计模式之建造者模式*************************/
    printf("建造者模式\n");
    Director *director = new Director();
    BuilderA *buildA = new BuilderA();
    BuilderB *buildB = new BuilderB();

    director->Construct(buildA);
    Product *pro1 = buildA->getResult();
    pro1->Show();

    director->Construct(buildB);
    Product *pro2 = buildB->getResult();
    pro2->Show();
}

void DesignPatterns::observer_display()
{
    /******************设计模式之观察者模式*************************/
    printf("观察者模式\n");
    StockObserver observer1("jams"), observer2("kobe");
    Boss boss;

    boss.addObserver(&observer1);
    boss.addObserver(&observer2);

    boss.Come();

    boss.delObserver(&observer1);
    boss.Leave();
}

void DesignPatterns::abstractFactory_display()
{
    /******************设计模式之抽象工厂模式*************************/
    printf("抽象工厂模式\n");
    Student *std = new Student();
    std->setId(1);
    std->setName("张三");
    Student *std1 = new Student();
    std1->setId(2);
    std1->setName("李四");

    SQL_Factory *sqlFactory = new SQLServerFactory();
    Student_SQL *studentSql = sqlFactory->createStudent_SQL();

    studentSql->Insert(std);
    studentSql->Insert(std1);

    printf("Name:%s\n", studentSql->getStudent(1)->getName().c_str());
}

void DesignPatterns::state_display()
{
    /******************设计模式之状态模式*************************/
    printf("状态模式\n");

    Work emergencyProject;

    emergencyProject.setHour(9);
    emergencyProject.writeProgram();

    emergencyProject.setHour(10);
    emergencyProject.writeProgram();

    emergencyProject.setHour(12);
    emergencyProject.writeProgram();

    emergencyProject.setHour(13);
    emergencyProject.writeProgram();

    emergencyProject.setHour(14);
    emergencyProject.writeProgram();

    emergencyProject.setHour(17);
    emergencyProject.writeProgram();
    emergencyProject.setFinish(true);
    // emergencyProject.setFinish(false);

    emergencyProject.setHour(19);
    emergencyProject.writeProgram();

    emergencyProject.setHour(22);
    emergencyProject.writeProgram();
}

void DesignPatterns::adapter_display()
{
    /******************设计模式之适配器模式*************************/
    printf("适配器模式\n");

    Player *z = new Forwark("詹姆斯");
    z->Attack();
    Player *k = new Forwark("库里");
    k->Defence();

    Player *ym = new Transmit("姚明");
    ym->Attack();
    ym->Defence();
}

void DesignPatterns::memento_display()
{
    /******************设计模式之备忘录模式*************************/
    printf("备忘录模式\n");

    GameCharacters *gamer = new GameCharacters("钢铁侠");
    gamer->initState();
    gamer->StateDisplay();

    // 保存进度
    RoleStateCaretaker *stateTaker = new RoleStateCaretaker();
    stateTaker->setRoleStateMememto(gamer->SaveState());

    gamer->Fight();
    gamer->StateDisplay();

    // 恢复
    gamer->RecoveryState(stateTaker->getRoleStateMememto());
    gamer->StateDisplay();
}

void DesignPatterns::compsite_display()
{
    /******************设计模式之组合模式*************************/
    printf("组合模式\n");

    ConcreateCompany *root = new ConcreateCompany("总公司");
    root->Add(new HRDepartment("总人力资源部"));
    root->Add(new FinanceDepartment("总财务部"));

    ConcreateCompany *comp = new ConcreateCompany("北方地区分公司");
    comp->Add(new HRDepartment("北方地区人力资源部"));
    comp->Add(new FinanceDepartment("北方地区财务部"));
    root->Add(comp);

    ConcreateCompany *comp1 = new ConcreateCompany("北京分公司");
    comp1->Add(new HRDepartment("北京分公司人力资源部"));
    comp1->Add(new FinanceDepartment("北京分公司财务部"));
    comp->Add(comp1);

    ConcreateCompany *comp2 = new ConcreateCompany("河北分公司");
    HRDepartment *hebeiHR = new HRDepartment("河北分公司人力资源部");
    comp2->Add(hebeiHR);
    comp2->Add(new FinanceDepartment("河北分公司财务部"));
    comp->Add(comp2);

    printf("结构图:\n");
    root->Display(1);

    printf("\n\n职责:\n");
    root->LineOfDuty();

    comp2->Remove(hebeiHR);

    printf("\n\nmove\n\n结构图:\n");
    root->Display(1);

    printf("\n\n职责:\n");
    root->LineOfDuty();
}

void DesignPatterns::bridge_display()
{
    /******************设计模式之桥接模式*************************/
    printf("桥接模式\n");

    Phone *phone;

    printf("手机A:\n");
    phone = new PhoneA();
    phone->setPhoneSoftware(new PhoneChat());
    phone->Run();
    phone->setPhoneSoftware(new PhoneGames());
    phone->Run();

    printf("手机B:\n");
    phone = new PhoneB();
    phone->setPhoneSoftware(new PhoneGames());
    phone->Run();
    phone->setPhoneSoftware(new PhoneChat());
    phone->Run();
}

void DesignPatterns::command_display()
{
    /******************设计模式之命令模式*************************/
    printf("命令模式\n");

    Cooking *boy = new Cooking();

    Command *beaf1 = new BeafCommand(boy);
    Command *beaf2 = new BeafCommand(boy);
    Command *chicken = new ChickenCommand(boy);
    Waiter *girl = new Waiter();

    // 营业
    girl->SetOrder(beaf1);
    girl->SetOrder(beaf2);
    girl->SetOrder(chicken);

    girl->Notify();
}

void DesignPatterns::responsibility_display()
{
    /******************设计模式之职责链模式*************************/
    printf("职责链模式\n\n");

    Manager *HR = new HRManager("人事经理");
    Manager *derector = new CommonManager("总监");
    Manager *general = new GeneralManager("董事");
    HR->setSuperManager(derector);
    derector->setSuperManager(general);

    Requesed request;

    request.requesedType = RequseType::vacation;
    request.description = "张三请假";
    request.num = 2;
    HR->RequesedHandle(request);

    request.requesedType = RequseType::vacation;
    request.description = "李四请假";
    request.num = 10;
    HR->RequesedHandle(request);

    request.requesedType = RequseType::vacation;
    request.description = "王五请假";
    request.num = 50;
    HR->RequesedHandle(request);

    request.requesedType = RequseType::raises;
    request.description = "张三加薪";
    request.num = 100;
    HR->RequesedHandle(request);

    request.requesedType = RequseType::raises;
    request.description = "李四加薪";
    request.num = 500;
    HR->RequesedHandle(request);

    request.requesedType = RequseType::raises;
    request.description = "王五加薪";
    request.num = 1000;
    HR->RequesedHandle(request);
}

void DesignPatterns::mediator_display()
{
    /******************设计模式之中介者模式*************************/
    printf("中介者模式\n\n");

    UnitedNationsSecurityCouncil *UNSC = new UnitedNationsSecurityCouncil();

    USA *usa = new USA(UNSC);
    Iraq *iraq = new Iraq(UNSC);

    UNSC->setUSA(usa);
    UNSC->setIraq(iraq);

    usa->Declare("不准研发核武器,否则将发动战争.");
    iraq->Declare("我们没有核武器,也不怕发动侵略!");
}

void DesignPatterns::flyWeight_display()
{
    /******************设计模式之享元模式*************************/
    printf("享元模式\n\n");

    WebSiteFactory *webfac = new WebSiteFactory();

    WebSite *z1 = webfac->getWebSite("产品展示");
    z1->Use(new User("张三"));

    WebSite *z2 = webfac->getWebSite("产品展示");
    z2->Use(new User("李四"));

    WebSite *z3 = webfac->getWebSite("产品展示");
    z3->Use(new User("王五"));

    WebSite *b1 = webfac->getWebSite("博客");
    b1->Use(new User("小明"));
    WebSite *b2 = webfac->getWebSite("博客");
    b2->Use(new User("小花"));

    printf("网站总数：%d\n", webfac->getWebSiteCount());
}

DesignPatterns::~DesignPatterns()
{
}