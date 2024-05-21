#include "TextQuery.h"

TextQuery::TextQuery(ifstream &ifs) : file(new vector<string>)
{
    string text;
    while (getline(ifs, text))
    {
        file->push_back(text);
        int n = file->size() - 1; // 当前行号
        istringstream line(text); // 将行文本分解为单词
        string word;
        while (line >> word)
        {
            // 如果单词不在wm中，以之为下标在wm中添加一项
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>); // 分配一个新的set
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // 如果未找到sought，我们将返回一个指向此set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // 使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // 未找到
    else
        return QueryResult(sought, loc->second, file);
}
