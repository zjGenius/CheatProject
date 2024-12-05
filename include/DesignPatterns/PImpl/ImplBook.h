/**
 * @file ImplBook.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief PIMPL模式“编译防火墙” 目的:将文件间编译依存关系降低
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _IMPL_BOOK_
#define _IMPL_BOOK_

#include <iostream>
#include <memory>

class ImplBook;

class PBook
{
private:
    std::string bookName;
    double price;

    std::unique_ptr<ImplBook> impl;

public:
    PBook(std::string, double);
    PBook(/* args */);
    ~PBook();

    // 私有成员为指针,禁止使用c++默认浅拷贝
    PBook(const PBook&) = delete;
    PBook& operator=(const PBook&) = delete;
    // 移动拷贝构造
    PBook(PBook&);
    PBook& operator=(PBook&&);

    void display();
};

#endif // !_IMPL_BOOK_