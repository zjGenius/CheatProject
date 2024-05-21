/**
 * @file QueryResult.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 文本查询程序 C++ primer 5 第12章末尾练习
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <algorithm>

using namespace std;
using line_no = vector<string>::size_type;

class TextQuery;
class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

private:
    string sought;                   // 查询单词
    shared_ptr<set<line_no>> lines;  // 出现的符号
    shared_ptr<vector<string>> file; // 输入文件
public:
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        : sought(s), lines(p), file(f){};

    // auto begin() { return (*lines).begin(); } // 这三个函数在书上的给定程序中好像并没有
    // auto end() { return lines->end(); }       // 给出，需要自己定义，后边会需要
    // auto get_file() { return file; }          //
};
