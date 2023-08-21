#include "Grammar.h"
#include "Sales_item.h"

#include <iostream>

void Grammar::test_while()
{
    int sum = 0, value = 0;
    // 读取数据直到遇到尾,计算所有和
    while (std::cin >> value)
        sum += value;
    std::cout << "sum:" << sum << std::endl;
}

void Grammar::test_sacle_item()
{
    // 支持从文件中获取参数 命令: ./ExternalPlugIn <test_in.txt >test_out.txt
    Sales_item book1, book2, book3;
    std::cout << "test1:" << std::endl;
    std::cin >> book1;
    std::cout << book1 << std::endl;

    std::cout << "test2:" << std::endl;
    std::cin >> book2;
    std::cout << "book1+book2:" << std::endl
              << book1 + book2 << std::endl;

    std::cout << "test3:" << std::endl;
    std::cin >> book3;
    std::cout << "book1+book2+book3:" << std::endl
              << book1 + book2 + book3 << std::endl;
}