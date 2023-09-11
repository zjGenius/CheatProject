/**
 * @file smartPointer.hpp
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 智能指针
 * @version 0.1
 * @date 2023-09-09
 * https://zhuanlan.zhihu.com/p/150555165
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <iostream>
#include <memory> //头文件
#include <algorithm>

// {
//     int *p = 100;
//     delete p;   //需要手动释放
// }

void MyPrint(int val)
{
    std::cout << val << " ";
}

void unique_ptr_test()
{
    std::unique_ptr<int> uptr = std::make_unique<int>(200);

    std::unique_ptr<int> uptr1 = std::move(uptr); // 用move来移动指针，此时uptr置空

    std::unique_ptr<int[]> uptr2 = std::make_unique<int[]>(10);
    for (int i = 0; i < 10; i++)
    {
        uptr2[i] = i * 2;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << uptr2[i] << " ";
    }
    std::cout << std::endl;

    // 结束后自动释放指针
}