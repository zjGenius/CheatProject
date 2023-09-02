#include "HeimaDisplay.h"

/**
 * @brief 重载的案例
 */
void HeimaDisplay::OperatorDisplay()
{
    // Operator::Person p1;
    // p1.setNumA(10);
    // p1.setNumB(5);

    // Operator::Person p2;
    // p2.setNumA(1);
    // p2.setNumB(2);

    // Operator::Person p3 = p1 + p2;

    // cout << "p1: " << p1 << endl;
    // cout << "p2: " << p2 << endl;
    // cout << "p3: numA:" << p3.getNumA() << " numB:" << p3.getNumB() << endl;

    // Operator::MyInteger myInt;
    // cout << ++(++myInt) << endl;
    // cout << myInt++ << endl;

    // cout << (myInt++)++ << endl;
    // cout << myInt << endl;

    // =重载
    // Operator::OperatorCopy o1(10);
    // Operator::OperatorCopy o2(20);
    // Operator::OperatorCopy o3(30);
    // cout << "o1 " << o1 << endl;
    // cout << "o2 " << o2 << endl;
    // cout << "o3 " << o3 << endl;
    // o1 = o2 = o3;
    // cout << "o1 " << o1 << endl;
    // cout << "o2 " << o2 << endl;
    // cout << "o3 " << o3 << endl;

    // 关系运算符重载
    Operator::OperatorRelation r1(10);
    Operator::OperatorRelation r2(20);
    cout << "result: r1" << ((r1 == r2) ? "等于" : "不等于") << "r2" << endl;
    cout << "result: r1" << ((r1 > r2) ? "大于" : ((r1 == r2) ? "等于" : "小于")) << "r2" << endl;
    cout << "result: r1" << ((r1 < r2) ? "小于" : ((r1 == r2) ? "等于" : "大于")) << "r2" << endl;
}
/**
 * @brief 多态的案例
 */
void HeimaDisplay::PolymorphicDisplay()
{
    polymorphic::Drink *drink = new polymorphic::Tea;
    drink->make();
    delete drink;

    drink = new polymorphic::Cofe;
    drink->make();
    delete drink;
}
void HeimaDisplay::ComputerDisplay()
{
    polymorphicComputer::Computer *com1 = new polymorphicComputer::Computer(new polymorphicComputer::IntelCPU(), new polymorphicComputer::IntelGPU(), new polymorphicComputer::IntelRAM());
    com1->work();
    cout << "------------------------" << endl;
    polymorphicComputer::Computer *com2 = new polymorphicComputer::Computer(new polymorphicComputer::LenvolCPU(), new polymorphicComputer::LenvolGPU(), new polymorphicComputer::LenvolRAM());
    com2->work();
    cout << "------------------------" << endl;
    polymorphicComputer::Computer *com3 = new polymorphicComputer::Computer(new polymorphicComputer::IntelCPU(), new polymorphicComputer::LenvolGPU(), new polymorphicComputer::IntelRAM());
    com3->work();
}

void HeimaDisplay::FileStreamDisplay()
{
    using namespace filestream;
    FileStream *stream;
    // stream->saveTxtFile("test1.txt");
    // stream->readTxtFile("test1.txt");
    // stream->saveBinaryFile("person.txt");
    // stream->readBinaryFile("person.txt");
    stream->fileIsEmpty("testEmpty.txt");
}

// 下面是测试三种模板类传入方式
template <class T1, class T2>
class Person_T
{
public:
    Person_T(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
    void show()
    {
        cout << "姓名:" << this->name << " 年龄:" << this->age << endl;
    }
    T1 name;
    T2 age;
};

// 指定传入类型 *常用
void printPerson1(Person_T<string, int> &p)
{
    cout << "1.指定传入类型" << endl;
    p.show();
    cout << endl;
}

void fun1()
{
    Person_T<string, int> p("孙悟空", 888);
    printPerson1(p);
}

// 参数模板化
template <class T1, class T2>
void printPerson2(Person_T<T1, T2> &p)
{
    cout << "2.参数模板化" << endl;
    p.show();
    cout << "T1 类型: " << typeid(T1).name() << endl;
    cout << "T2 类型: " << typeid(T2).name() << endl;
    cout << endl;
}

void fun2()
{
    Person_T<string, int> p("孙悟空", 888);
    printPerson2(p);
}

// 类模板化
template <class T>
void printPerson3(T &p)
{
    cout << "3.类模板化" << endl;
    p.show();
    cout << "T 类型: " << typeid(T).name() << endl;
    cout << endl;
}

void fun3()
{
    Person_T<string, int> p("孙悟空", 888);
    printPerson3(p);
}

void printfHeimaMyArray1(HeimaMyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void HeimaDisplay::TemplateDisplay()
{
    using namespace template_heima;
    Template t;
    cout << "函数模板:" << endl;
    // t.templateSwap();
    // t.templateArraySwap();
    t.templateCompare();

    ClassTemplate<string, int> c("孙悟空", 999);
    cout << "类模板:" << endl;
    c.ShowInfo();

    cout << endl
         << "三种传入方式:" << endl;
    // 这里如果打印会有问题，需要在执行时加上 | c++filt -t
    // https://blog.csdn.net/lovefengruoqing/article/details/93377021
    fun1();
    fun2();
    fun3();

    cout << endl
         << "模板类构造函数与成员函数 类内申明,内外实现：" << endl;
    HeimaClassTemplate<string, int> ct("沙师弟", 998);
    ct.ShowInfo();

    cout << endl
         << "友元函数 类内实现与类外实现" << endl;
    HeimaFriendTemplate<string, int> ft("Tom", 12);
    printfInside(ft);
    printfOutside(ft);

    cout << endl
         << "自定义数组" << endl;

    HeimaMyArray<int> arr1(10);
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1" << endl;
    printfHeimaMyArray1(arr1);
    cout << "arr1 index3:  " << arr1[3] << endl;
    cout << "arr1 size:  " << arr1.getSize() << endl;
    cout << "arr1 capacity:  " << arr1.getCapacity() << endl;

    HeimaMyArray<int> arr2(arr1);
    arr2.Pop_Back();
    cout << "arr2" << endl;
    printfHeimaMyArray1(arr2);
    cout << "arr2 index3:  " << arr2[6] << endl;
    cout << "arr2 size:  " << arr2.getSize() << endl;
    cout << "arr2 capacity:  " << arr2.getCapacity() << endl;
}
