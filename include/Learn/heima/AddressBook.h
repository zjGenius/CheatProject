#ifndef _ADDRESSBOOK_H_
#define _ADDRESSBOOK_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::find
#include "log.h"

using namespace std;

#define PEOPLE_MAX 5

#pragma pack(1)

struct BookStruct
{
    int id = 0;      // 序号
    string name;     // 姓名
    int sex;         // 性别
    int age;         // 年龄
    string phoneNum; // 电话号码
    string address;  // 家庭住址
};

struct AddressBooks
{
    BookStruct mAddress[PEOPLE_MAX];
    int mSize;
};

#pragma pack()

class AddressBook
{
private:
private:
    void showMenu();
    void addAddress(AddressBooks *abs);
    void showAddress(AddressBooks *abs);
    vector<int> isExist(AddressBooks *abs, uint8_t mode, string data);
    void findAddress(AddressBooks *abs);
    void deleteAddress(AddressBooks *abs);
    void modifyAddress(AddressBooks *abs);
    void clearAddress(AddressBooks *abs);
    void PAUSE();

public:
    AddressBook();
    ~AddressBook();

    void startAddressSystem();
};

#endif // !_ADDRESSBOOK_H_