/**
 * @file HeimaMyArray.hpp
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 自定义数组类
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <iostream>
using namespace std;

template <class T>
class HeimaMyArray
{
private:
    T *mAddress;    // 指针，指向堆区的数据
    int m_capacity; // 容量
    int m_size;     // 大小

public:
    HeimaMyArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->mAddress = new T[this->m_capacity];
    }

    // 拷贝构造函数
    HeimaMyArray(const HeimaMyArray &arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->mAddress = new T[this->m_capacity];    //这是默认拷贝构造函数的弊端，所以需要自己重写

        this->mAddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->mAddress[i] = arr.mAddress[i];
        }
    }

    // operator= 赋值运算符 防止浅拷贝
    HeimaMyArray &operator=(const HeimaMyArray &arr)
    {
        if (this->mAddress != NULL)
        {
            delete[] this->mAddress;
            this->mAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->mAddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->mAddress[i] = arr.mAddress[i];
        }
        return *this;
    }

    // 尾插法
    void Push_Back(const T &val)
    {
        if (this->m_size == this->m_capacity)
        {
            cout << "容量已满" << endl;
            return;
        }
        this->mAddress[this->m_size] = val;
        this->m_size++;
    }

    // 尾删法
    void Pop_Back()
    {
        if (this->m_size == 0)
        {
            cout << "数组中没有元素" << endl;
            return;
        }
        this->m_size--;
    }

    // 获取元素
    T &operator[](int index)
    {
        if (index < 0 || index > this->m_size) // 用户自己去处理越界问题
        {
            cout << "该位置没有元素" << endl;
            // return *(T *)&NULL;
        }
        return this->mAddress[index];
    }

    int getSize()
    {
        return this->m_size;
    }

    int getCapacity()
    {
        return this->m_capacity;
    }

    ~HeimaMyArray()
    {
        if (this->mAddress != NULL)
        {
            delete[] this->mAddress;
            this->mAddress = NULL;
        }
    }
};
