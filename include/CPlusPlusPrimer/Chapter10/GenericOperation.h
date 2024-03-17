/**
 * 第10章 泛型编程 之迭代器
 * 1、lambda函数表达式
 * 2、bind标准库函数
 * 3、迭代器分为5类：
 *      1) 输入迭代器 istream_iterator
 *      2) 输出迭代器 ostream_iterator
 *      3) 前向迭代器 forward_list
 *      4) 双向迭代器 list
 *      5) 随机访问迭代器 vector string array deque  
*/

#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>
#include <numeric>

using namespace std;
using namespace std::placeholders;

void test_lambda();
void test_inserter();
void test_bind();
void test_iostream();
void test_10_30();
void test_10_31();
void test_rbegin_rend();
void test_10_34();