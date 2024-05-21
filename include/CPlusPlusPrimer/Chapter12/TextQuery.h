/**
 * @file TextQuery.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 文本查询程序
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "QueryResult.h"
#include <map>

using namespace std;

class TextQuery
{

public:
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;          // 输入文件
    map<string, shared_ptr<set<line_no>>> wm; // 每个单词到它所在的行号的集合的映射
};
