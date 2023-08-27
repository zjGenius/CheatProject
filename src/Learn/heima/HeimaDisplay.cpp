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
