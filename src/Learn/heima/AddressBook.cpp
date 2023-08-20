#include "AddressBook.h"

AddressBook::AddressBook()
{
}

AddressBook::~AddressBook()
{
}

void AddressBook::PAUSE()
{
    system("read -p '按任意键继续...' var");
}
/**
 * @brief 主菜单
 *
 */
void AddressBook::showMenu()
{
    cout << "*************************" << endl;
    cout << "*******1.新增联系人******" << endl;
    cout << "*******2.显示联系人******" << endl;
    cout << "*******3.删除联系人******" << endl;
    cout << "*******4.查找联系人******" << endl;
    cout << "*******5.修改联系人******" << endl;
    cout << "*******6.清空联系人******" << endl;
    cout << "*******0.退出通讯录******" << endl;
    cout << "*************************" << endl;
}
/**
 * @brief 新增联系人
 *
 * @param abs
 */
void AddressBook::addAddress(AddressBooks *abs)
{
    if (abs->mSize >= PEOPLE_MAX)
    {
        LOG_RED("通讯录已满\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }
    system("clear"); // 清屏
    cout << "*********增加联系人********" << endl
         << endl;

    cout << "请输入联系人姓名" << endl;
    string name;
    cin >> name;
    abs->mAddress[abs->mSize].name = name;

    cout << "请输入联系人性别"
         << "   1--男  2--女" << endl;
    int sex = 0;
    while (1)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->mAddress[abs->mSize].sex = sex;
            break;
        }
        cout << "输入有误,请重新输入" << endl;
    }

    cout << "请输入联系人年龄" << endl;
    int age = 0;
    while (1)
    {
        cin >> age;
        if (age > 3 && age < 150)
        {
            abs->mAddress[abs->mSize].age = age;
            break;
        }
        cout << "输入有误,请重新输入" << endl;
    }

    cout << "请输入联系人电话号码" << endl;
    string phone;
    while (1)
    {
        cin >> phone;
        vector<int> phone_vec = isExist(abs, 1, phone);

        if (phone.size() == 11)
        {
            if (phone_vec.size() == 0)
            {
                abs->mAddress[abs->mSize].phoneNum = phone;
                break;
            }
            cout << "已存在,是否继续输入  1-是 其他-不是" << endl;
            int num;
            cin >> num;
            if (num == 1)
                continue;
            else
            {
                system("clear");
                return;
            }
        }
        cout << "输入有误,请重新输入" << endl;
    }

    cout << "请输入联系人住址" << endl;
    string address;
    cin >> address;
    abs->mAddress[abs->mSize].address = address;

    LOG_GREEN("添加成功!\n");
    PAUSE();
    system("clear"); // 清屏
    abs->mAddress[abs->mSize].id = abs->mSize + 1;
    abs->mSize++;
}

/**
 * @brief 显示联系人
 *
 * @param abs
 */
void AddressBook::showAddress(AddressBooks *abs)
{
    if (abs->mSize == 0)
    {
        LOG_RED("通讯录为空\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }

    system("clear"); // 清屏
    cout << "*********显示联系人********" << endl
         << endl;

    cout << "序号\t"
         << "姓名\t"
         << "性别\t"
         << "年龄\t"
         << "电话号码\t"
         << "家庭住址\t" << endl;

    for (int i = 0; i < abs->mSize; i++)
    {
        cout << abs->mAddress[i].id << "\t";
        cout << abs->mAddress[i].name << "\t";
        cout << (abs->mAddress[i].sex == 1 ? "男" : "女")
             << "\t";
        cout << abs->mAddress[i].age << "\t";
        cout << abs->mAddress[i].phoneNum << "\t";
        cout << abs->mAddress[i].address << "\t" << endl;
    }
    cout << " " << endl;
}

/**
 * @brief 查找联系人
 *
 * @param abs
 */
void AddressBook::findAddress(AddressBooks *abs)
{
    if (abs->mSize == 0)
    {
        LOG_RED("通讯录为空\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;

    vector<int> addressVec = isExist(abs, 0, name);
    if (addressVec.size() == 0)
    {
        LOG_RED("查无此人\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }
    system("clear"); // 清屏
    cout << "序号\t"
         << "姓名\t"
         << "性别\t"
         << "年龄\t"
         << "电话号码\t"
         << "家庭住址\t" << endl;

    for (int i = 0; i < abs->mSize; i++)
    {
        vector<int>::iterator it = find(addressVec.begin(), addressVec.end(), abs->mAddress[i].id);
        if (it != addressVec.end())
        {
            cout << abs->mAddress[i].id << "\t";
            cout << abs->mAddress[i].name << "\t";
            cout << (abs->mAddress[i].sex == 1 ? "男" : "女")
                 << "\t";
            cout << abs->mAddress[i].age << "\t";
            cout << abs->mAddress[i].phoneNum << "\t";
            cout << abs->mAddress[i].address << "\t" << endl;
        }
    }
}

/**
 * @brief 查找函数
 *
 * @param abs
 * @param mode 模式 0-姓名 1-电话
 * @param data
 * @return vector<int>
 */
vector<int> AddressBook::isExist(AddressBooks *abs, uint8_t mode, string data)
{
    vector<int> addressVec;
    for (int i = 0; i < abs->mSize; i++)
    {
        switch (mode)
        {
        case 0:
        {
            if (strstr(abs->mAddress[i].name.c_str(), data.c_str()) != NULL)
                addressVec.push_back(abs->mAddress[i].id);
        }
        break;
        case 1:
        {
            if (abs->mAddress[i].phoneNum == data)
                addressVec.push_back(abs->mAddress[i].id);
        }
        break;
        }
    }

    return addressVec;
}
/**
 * @brief 删除联系人
 *
 * @param abs
 */
void AddressBook::deleteAddress(AddressBooks *abs)
{
    if (abs->mSize == 0)
    {
        LOG_RED("通讯录为空\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }
    cout << "请输入要删除的联系人id" << endl;
    int delId = 0;
    while (1)
    {
        cin >> delId;
        if (delId > 0 && delId <= abs->mSize)
        {
            delId -= 1;
            break;
        }
        cout << "没有该id,请重新输入" << endl;
    }

    for (int i = delId; i < abs->mSize - 1; i++)
    {
        abs->mAddress[i] = abs->mAddress[i + 1];
        abs->mAddress[i].id--;
    }
    abs->mSize--;
    LOG_GREEN("删除成功!\n");
    PAUSE();
    system("clear"); // 清屏
}

/**
 * @brief 修改联系人
 *
 * @param abs
 */
void AddressBook::modifyAddress(AddressBooks *abs)
{
    if (abs->mSize == 0)
    {
        LOG_RED("通讯录为空\n");
        PAUSE();
        system("clear"); // 清屏
        return;
    }
    cout << "请输入要修改的联系人id" << endl;
    int id;
    while (1)
    {
        cin >> id;
        if (id > 0 && id <= abs->mSize)
        {
            id -= 1;
            break;
        }
        cout << "没有该id,请重新输入" << endl;
    }
    int num = 0;
    while (1)
    {
        cout << "修改" << abs->mAddress[id].name << "信息 1-姓名 2-性别 3-年龄 4-电话号码 5-家庭住址 0-退出修改" << endl;
        cin >> num;
        switch (num)
        {
        case 1:
        {
            string name;
            cout << "修改姓名" << endl;
            cin >> name;
            abs->mAddress[id].name = name;
        }
        break;

        case 2:
        {
            int sex = 0;
            cout << "修改性别"
                 << "   1--男  2--女" << endl;
            while (1)
            {
                cin >> sex;
                if (sex == 1 || sex == 2)
                    break;
                cout << "输入有误,重新输入" << endl;
            }
            abs->mAddress[id].sex = sex;
        }
        break;

        case 3:
        {
            cout << "修改年龄" << endl;
            int age = 0;
            while (1)
            {
                cin >> age;
                if (age > 3 && age < 150)
                {
                    abs->mAddress[id].age = age;
                    break;
                }
                cout << "输入有误,请重新输入" << endl;
            }
        }
        break;

        case 4:
        {
            cout << "修改号码" << endl;
            string phone;
            while (1)
            {
                cin >> phone;
                vector<int> phone_vec = isExist(abs, 1, phone);

                if (phone.size() == 11)
                {
                    if (phone_vec.size() == 0)
                    {
                        abs->mAddress[id].phoneNum = phone;
                        break;
                    }
                    cout << "已存在,是否继续输入  1-是 其他-不是" << endl;
                    int num;
                    cin >> num;
                    if (num == 1)
                        continue;
                    else
                    {
                        system("clear");
                        return;
                    }
                }
                cout << "输入有误,请重新输入" << endl;
            }
        }
        break;
        case 5:
        {
            cout << "修改住址" << endl;
            string address;
            cin >> address;
            abs->mAddress[id].address = address;
        }
        break;
        case 0:
        {
            LOG_GREEN("修改完成\n");
            PAUSE();
            system("clear"); // 清屏
            return;
        }
        break;

        default:
            cout << "输入有误,重新输入" << endl;
            break;
        }
    }

    for (int i = id; i < abs->mSize; i++)
    {
        abs->mAddress[i] = abs->mAddress[i + 1];
        abs->mAddress[i].id--;
    }

    LOG_GREEN("修改成功!\n");
    PAUSE();
    system("clear"); // 清屏
}

void AddressBook::clearAddress(AddressBooks *abs)
{
    cout << "是否清空? 1-确定 其他-取消" << endl;
    int num = 0;
    cin >> num;
    if (num != 1)
        return;

    abs->mSize = 0;
    LOG_GREEN("清空成功!\n");
    PAUSE();
    system("clear"); // 清屏
}

void AddressBook::startAddressSystem()
{
    // 创建通讯录结构体数组
    AddressBooks abs;
    abs.mSize = 0;
    system("clear"); // 清屏
    cout << "*********欢迎光临********" << endl;

    int select;

    while (1)
    {
        showMenu(); // 显示菜单
        cout << "选择需要的服务" << endl;
        cin >> select;

        switch (select)
        {
        case 1: // 增加联系人
            addAddress(&abs);
            break;
        case 2: // 显示联系人
            showAddress(&abs);
            break;
        case 3: // 删除联系人
            deleteAddress(&abs);
            break;
        case 4: // 查找联系人
            findAddress(&abs);
            break;
        case 5: // 修改联系人
            modifyAddress(&abs);
            break;
        case 6: // 清空联系人
            clearAddress(&abs);
            break;
        case 0:
        {
            cout << "欢迎下次光临" << endl;
            return;
        }
        default:
            // LOG_RED("没有此项服务\n");
            LOG_RED("没有此项服务\n");
            PAUSE();
            system("clear");
            break;
        }
    }
}
