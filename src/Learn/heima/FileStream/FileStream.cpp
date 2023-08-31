#include "FileStream.h"
using namespace filestream;
using namespace std;

void FileStream::saveTxtFile(char *filename)
{
    fstream file;
    file.open(filename, ios::out);

    file << "姓名:张三" << endl;
    file << "性别:男" << endl;
    file << "年龄:18" << endl;

    file.close();
    cout << "file save success" << endl;
}

void FileStream::readTxtFile(char *filename)
{
    fstream file;
    file.open(filename, ios::in);

    if (!file.is_open())
    {
        cout << "file open fail!" << endl;
        return;
    }

    // 第一种
    // char buffer[1024];
    // while (file >> buffer)
    // {
    //     cout << buffer << endl;
    // }

    // 第二种
    // char buffer[1024];
    // while (file.getline(buffer, sizeof(buffer)))
    // {
    //     cout << buffer << endl;
    // }

    // 第三种
    // string buffer;
    // while (getline(file, buffer))
    // {
    //     cout << buffer << endl;
    // }

    // 第四种 不建议，效率低
    // char buffer;
    // while ((buffer = file.get()) != EOF)
    // {
    //     cout << buffer;
    // }

    file.close();
}

void FileStream::saveBinaryFile(char *filename)
{
    fstream ifs;

    ifs.open(filename, ios::out | ios::binary);

    Person p{"张三", 18};

    ifs.write((const char *)&p, sizeof(Person));

    ifs.close();
    cout << "file save success" << endl;
}

void FileStream::readBinaryFile(char *filename)
{
    fstream ifs;

    ifs.open(filename, ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "file open fail!" << endl;
        return;
    }

    Person p;

    ifs.read((char *)&p, sizeof(Person));

    cout << "姓名:" << p.mName << "age:" << p.mAge << endl;

    ifs.close();
}

void FileStream::fileIsEmpty(char *filename)
{
    fstream ifs;

    ifs.open(filename, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        return;
    }

    char buffer[1024];
    while (ifs >> buffer)
    {
        cout << buffer << endl;
    }

    // string buffer;
    // while (getline(ifs, buffer))
    // {
    //     cout << buffer << endl;
    // }

    // char buffer[1024];
    // while (ifs.getline(buffer, sizeof(buffer)))
    // {
    //     cout << buffer << endl;
    // }

    ifs.close();
}