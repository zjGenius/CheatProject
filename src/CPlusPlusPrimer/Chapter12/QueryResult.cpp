#include "QueryResult.h"

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occors " << qr.lines->size() << " " << " times " << endl; // 输出关键词和出现次数
    for (auto num : *qr.lines)
    {
        os << " \t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl; // 输出关键词所在行
    }
    return os;
}
