#include "GenericOperation.h"

/**
 * lambda表达式
 */
void test_lambda()
{
    vector<int> int_vec;
    for (int i = 0; i < 10; ++i)
    {
        int_vec.push_back(2 * i - 5);
    }

    transform(int_vec.begin(), int_vec.end(), int_vec.begin(),
              [](int i) -> int
              { if(i < 0) return -i; else return i; });
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
ostream &prinf_bind(ostream &os, const string &s, char c)
{
    return os << s << c;
}

/**
 * bind标准库函数的使用
 * 通用函数适配器
 * ref函数
 */
void test_bind()
{
    auto check6 = bind(check_size, _1, 5); // _1为占位符 [:需要进行定义 using namespace std::placeholders;
    string s = "hello";
    bool b1 = check6(s);
    cout << "check6: " << b1 << endl;

    ostream &os = cout;
    const char c = ' ';
    vector<string> words = {"i", "am", "a", "supper", "man"};
    cout << "lambda:" << endl;
    for_each(words.begin(), words.end(),
    [&os, c](const string &s)
    {
        os << s << c;
    });
    cout << endl;

    cout << "bind:" << endl;
    for_each(words.begin(), words.end(), bind(prinf_bind, ref(os), _1, ' ')); // 函数ref返回一个对象，包含给定的引用，此对象可以拷贝 [:定义在头文件<functional>
    cout << endl;
}

/**
 * 迭代器使用
 */
void test_inserter()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst1, lst2;

    // 插入迭代器 back_inserter front_inserter inserter
    copy(lst.begin(), lst.end(), front_inserter(lst1));
    copy(lst.begin(), lst.end(), inserter(lst2, lst2.begin()));

    // 流迭代器 ostream_iterator istream_iterator
    ostream_iterator<int> out_iter(cout, " ");

    cout << "front_inserter:" << endl;
    copy(lst1.begin(), lst1.end(), out_iter);
    cout << endl;

    cout << "inserter:" << endl;
    copy(lst2.begin(), lst2.end(), out_iter);
    cout << endl;
}

/**
 * 流迭代器
 * 从文件流中取数据，通过流迭代器输入输出
 */
void test_iostream()
{
    ifstream in_ifs("test1.txt");
    istream_iterator<string> str_it(in_ifs), str_eof;
    vector<string> str_vec;

    while (str_it != str_eof)
    {
        str_vec.push_back(*str_it++);
    }

    ostream_iterator<string> str_ot(cout, " ");

    copy(str_vec.begin(), str_vec.end(), str_ot);
    cout << endl;

    // 迭代器与算法使用
    istream_iterator<int> int_in(cin), int_eof;
    cout << accumulate(int_in, int_eof, 0) << endl;
}

/**
 * 反向迭代器
*/
void test_10_30()
{
    istream_iterator<int> int_in(cin), int_eof;
    vector<int> int_vec;
    ostream_iterator<int> int_out(cout, " ");

    copy(int_in, int_eof, inserter(int_vec, int_vec.begin()));

    cout << "原始数据:" << endl;
    copy(int_vec.begin(), int_vec.end(), int_out);
    cout << endl;

    sort(int_vec.begin(), int_vec.end());
    cout << "排序后:" << endl;
    copy(int_vec.begin(), int_vec.end(), int_out);
    cout << endl;
}

void test_10_31()
{
    istream_iterator<int> int_in(cin), int_eof;
    vector<int> int_vec;
    ostream_iterator<int> int_out(cout, " ");

    copy(int_in, int_eof, inserter(int_vec, int_vec.begin()));

    cout << "unique 原始数据:" << endl;
    copy(int_vec.begin(), int_vec.end(), int_out);
    cout << endl;

    sort(int_vec.begin(), int_vec.end());
    cout << "排序后:" << endl;
    unique_copy(int_vec.begin(), int_vec.end(), int_out);
    cout << endl;
}

void test_rbegin_rend()
{
    string line = "FIRST,MIDDLE,LAST";

    // begin和cbegin的区别：cbegin是const类型

    // 输出FIRST
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;

    // 输出TSAL
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(line.crbegin(), rcomma) << endl;

    // 输出LAST
    auto rcomma1 = find(line.crbegin(), line.crend(), ',');
    cout << string(rcomma1.base(), line.cend()) << endl;
}

void test_10_34()
{
    cout << "练习题10.34:" << endl;
    vector<int> int_vec = {1, 2, 3, 4, 5};
    ostream_iterator<int> int_out(cout, " ");

    copy(int_vec.cbegin(), int_vec.cend(), int_out);
    cout << endl;

    copy(int_vec.crbegin(), int_vec.crend(), int_out);
    cout << endl;
}