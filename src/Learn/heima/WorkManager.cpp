#include "WorkManager.h"

using namespace workManagerSpace;

void PAUSE()
{
    system("read -p '按任意键继续...' var");
}

Employee::Employee(int id, string name, int did)
{
    mDid = id;
    mName = name;
    mDid = did;
}
void Employee::showInfo()
{
    cout << "职工编号:" << mId
         << "\t职工姓名:" << mName
         << "\t岗位:" << getDepartName()
         << "\t岗位职责: 完成经理交给的任务" << endl;
}
string Employee::getDepartName()
{
    return "员工";
}

Manager::Manager(int id, string name, int did)
{
    mDid = id;
    mName = name;
    mDid = did;
}
void Manager::showInfo()
{
    cout << "职工编号:" << mId
         << "\t职工姓名:" << mName
         << "\t岗位:" << getDepartName()
         << "\t岗位职责: 完成老板交给的任务,并交给员工" << endl;
}
string Manager::getDepartName()
{
    return "经理";
}

Boss::Boss(int id, string name, int did)
{
    mDid = id;
    mName = name;
    mDid = did;
}
void Boss::showInfo()
{
    cout << "职工编号:" << this->mId
         << "\t职工姓名:" << this->mName
         << "\t岗位:" << this->getDepartName()
         << "\t岗位职责: 管理公司" << endl;
}
string Boss::getDepartName()
{
    return "老板";
}

void WorkManager::showMenu()
{
    cout << "*************************************" << endl;
    cout << "**************职工管理系统***********" << endl;
    cout << "**************0 退出系统*************" << endl;
    cout << "**************1 新增职工*************" << endl;
    cout << "**************2 显示职工*************" << endl;
    cout << "**************3 修改职工*************" << endl;
    cout << "**************4 查找职工*************" << endl;
    cout << "**************5 删除职工*************" << endl;
    cout << "**************6 职工排序*************" << endl;
    cout << "**************7 清空职工*************" << endl;
    cout << "*************************************" << endl;
}

void WorkManager::startSystem()
{
    system("clear");
    showMenu();

    Woker *worker1 = new Employee(1, "张三", 1);
    worker1->showInfo();
    Woker *worker2 = new Manager(2, "李四", 1);
    worker2->showInfo();
    Woker *worker3 = new Boss(3, "王五", 1);
    worker3->showInfo();

    int select;

    while (1)
    {
        cout << "请输入选择:" << endl;
        cin >> select;
        switch (select)
        {

        case 0:
            cout << "欢迎下次光临" << endl;
            exit(0);
            break;
        default:
            system("clear");

            showMenu();
            cout << "输入有误,请重新选择" << endl;
            break;
        }
    }
}