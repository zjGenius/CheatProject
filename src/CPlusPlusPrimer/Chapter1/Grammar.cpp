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

void Grammar::test_count()
{
    int count = 1, num, old_num = 0;

    while (std::cin >> num)
    {
        if (count == 1 && old_num == 0)
        {
            old_num = num;
            continue;
        }

        if (num == old_num)
        {
            count++;
        }
        else
        {
            std::cout << "num:" << old_num << " " << count << " times" << std::endl;
            count = 1;
        }

        old_num = num;
    }
    std::cout << "num:" << old_num << " " << count << " times" << std::endl;
}

void Grammar::test_count1()
{
    int currVal, val;

    if (std::cin >> currVal)
    {
        int num = 1;
        while (std::cin >> val)
        {
            if (currVal == val)
            {
                num++;
            }
            else
            {
                std::cout << "num:" << currVal << " " << num << " times" << std::endl;
                currVal = val;
                num = 1;
            }
        }
        std::cout << "num:" << currVal << " " << num << " times" << std::endl;
    }
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