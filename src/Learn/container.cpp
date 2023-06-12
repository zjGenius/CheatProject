/**
 * @file container.cpp
 * @author zhangjun
 * @brief 该程序是练习各种
 * @version 0.1
 * @date 2023-06-12
 *
 * @copyright Copyright (c) 2023
 * 代办:
 *  spdlog 日志,后续查看一下
 */
#include "container.h"

/**
 * @brief deque队列的测试程序
 *
 */
void deque_test()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> q;
    for (int i = 0; i <= 9; i++)
    {
        if (i % 2 == 0)
            q.push_front(a[i]);
        else
            q.push_back(a[i]);
    } /*此时队列里的内容是: {8,6,4,2,0,1,3,5,7,9}*/
    LOG_D("orgin deque");
    for (deque<int>::iterator it = q.begin(); it != q.end(); it++)
    {
        printf(" %d", *it);
    }
    printf("\n");
    q.pop_front(); /*清除第一个元素后输出第一个(8)*/
    LOG_D("clear first %d\n", q.front());
    q.pop_back(); /*清除最后一个元素后输出最后一个(9)*/
    LOG_D("clear end %d\n", q.back());
    LOG_D("deque");

    for (deque<int>::iterator it = q.begin(); it != q.end(); it++)
    {
        printf(" %d", *it);
    }
    printf("\n");
}

int fun(int acc, int num)
{
    return acc + num * 3;
}
/**
 * @brief list的测试程序
 * List是stl实现的双向链表，与向量(vectors)相比, 它允许快速的插入和删除，但是随机访问却比较慢。使用时需要添加头文件 #include <list>
 * 常用的操作函数:
    Lst1.assign() 给list赋值
    Lst1.back() 返回最后一个元素
    Lst1.begin() 返回指向第一个元素的迭代器
    Lst1.clear() 删除所有元素
    Lst1.empty() 如果list是空的则返回true
    Lst1.end() 返回末尾的迭代器
    Lst1.erase() 删除一个元素
    Lst1.front() 返回第一个元素
    Lst1.get_allocator() 返回list的配置器
    Lst1.insert() 插入一个元素到list中
    Lst1.max_size() 返回list能容纳的最大元素数量
    Lst1.merge() 合并两个list
    Lst1.pop_back() 删除最后一个元素
    Lst1.pop_front() 删除第一个元素
    Lst1.push_back() 在list的末尾添加一个元素
    Lst1.push_front() 在list的头部添加一个元素
    Lst1.rbegin() 返回指向第一个元素的逆向迭代器
    Lst1.remove() 从list删除元素
    Lst1.remove_if() 按指定条件删除元素
    Lst1.rend() 指向list末尾的逆向迭代器
    Lst1.resize() 改变list的大小
    Lst1.reverse() 把list的元素倒转
    Lst1.size() 返回list中的元素个数
    Lst1.sort() 给list排序
    Lst1.splice() 合并两个list
    Lst1.swap() 交换两个list
    Lst1.unique() 删除list中相邻重复的元素
 */
void list_test()
{
    printf("*********************list test start*********************\n");
    list<int> listOne;
    // 头部插入元素
    listOne.push_front(3);
    listOne.push_front(2);
    listOne.push_front(1);
    // 尾部插入元素
    listOne.push_back(4);
    listOne.push_back(5);
    listOne.push_back(6);
    // 从左往右索引list所有元素
    LOG_D("left->right list:");
    for (list<int>::iterator it = listOne.begin(); it != listOne.end(); it++)
        printf(" %d", *it);
    printf("\n");
    // 从右往左索引list所有元素
    LOG_D("right->left list:");
    for (list<int>::reverse_iterator it = listOne.rbegin(); it != listOne.rend(); it++)
        printf(" %d", *it);
    printf("\n");
    /********************************************************************************************/

    // 创建3个元素为2的list
    list<int> listTwo(3, 2);
    for (list<int>::iterator it = listTwo.begin(); it != listTwo.end(); it++)
        printf(" %d", *it);
    printf("\n");
    // 容器求和 头文件#include <numeric>
    int sum1 = accumulate(listTwo.begin(), listTwo.end(), 0);
    LOG_D("sum: %d\n", sum1);
    // 容器求和 自定义求和规则
    int sum2 = accumulate(listTwo.begin(), listTwo.end(), 0, fun);
    LOG_D("sum: %d\n", sum2);
    /********************************************************************************************/

    // 创建char元素的list
    list<int> listChar;
    listChar.push_front('C');
    listChar.push_front('B');
    listChar.push_front('A');

    listChar.push_back('D');
    listChar.push_back('E');
    listChar.push_back('F');

    LOG_D("listChar:");
    for (list<int>::iterator it = listChar.begin(); it != listChar.end(); it++)
        printf(" %c", char(*it));
    printf("\n");

    list<int>::iterator max = max_element(listChar.begin(), listChar.end());
    LOG_D("Max Char: %c\n", char(*max));
    /********************************************************************************************/

    list<int> list1;
    list1.assign(8, 1);
    LOG_D("list1 assign:");
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
        printf(" %d", *it);
    printf("\n");

    list1.insert(++list1.begin(), 3, 9);
    LOG_D("list1 insert:");
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
        printf(" %d", *it);
    printf("\n");

    list1.erase(list1.begin());
    LOG_D("list1 erase:");
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
        printf(" %d", *it);
    printf("\n");

    LOG_D("list1 max_size: %ld\n", list1.max_size());
    LOG_D("list1 size: %ld\n", list1.size());
    LOG_D("list1 empty: %d\n", list1.empty());

    list1.sort();
    LOG_D("list1 sort:");
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
        printf(" %d", *it);
    printf("\n");

    list<int> list2;
    list2.push_front(7);
    list2.push_front(6);
    list2.push_front(5);

    list1.splice(++list1.begin(), list2);
    LOG_D("list1 splice list2:");
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
        printf(" %d", *it);
    printf("\n");

    printf("**************************end***************************\n");
}

/**
 * @brief map的测试程序
 * 常用的操作函数:
    begin()         返回指向map头部的迭代器
    clear(）        删除所有元素
    count()         返回指定元素出现的次数
    empty()         如果map为空则返回true
    end()           返回指向map末尾的迭代器
    equal_range()   返回特殊条目的迭代器对
    erase()         删除一个元素
    find()          查找一个元素
    get_allocator() 返回map的配置器
    insert()        插入元素
    key_comp()      返回比较元素key的函数
    lower_bound()   返回键值>=给定元素的第一个位置
    max_size()      返回可以容纳的最大元素个数
    rbegin()        返回一个指向map尾部的逆向迭代器
    rend()          返回一个指向map头部的逆向迭代器
    size()          返回map中元素的个数
    swap()           交换两个map
    upper_bound()    返回键值>给定元素的第一个位置
    value_comp()     返回比较元素value的函数
 * @param Mode 
    1.Mode==0 小于号 < 重载
    2.Mode==1 仿函数的应用，这个时候结构体中没有直接的小于号重载
 */
void map_test(int Mode)
{
    // 存储pair类型的数据
    map<int, string> mapStudent1;
    mapStudent1.insert(pair<int, string>(1, "student1"));
    mapStudent1.insert(pair<int, string>(2, "student2"));
    mapStudent1.insert(pair<int, string>(3, "student3"));
    LOG_D("map insert pair:\n");
    for (map<int, string>::iterator it = mapStudent1.begin(); it != mapStudent1.end(); it++)
        printf("\tkey: %d, value: %s\n", it->first, it->second.c_str());
    printf("\n");

    // 存储value_type类型的数据  解释：通俗的说value_type 就是stl容器盛装的数据的数据类型 (https://www.cnblogs.com/huty/p/8517000.html)
    map<int, string> mapStudent2;
    mapStudent2.insert(map<int, string>::value_type(1, "student_one"));
    mapStudent2.insert(map<int, string>::value_type(2, "student_two"));
    mapStudent2.insert(map<int, string>::value_type(3, "student_three"));
    LOG_D("map insert value_type:\n");
    for (map<int, string>::iterator it = mapStudent2.begin(); it != mapStudent2.end(); it++)
        printf("\tkey: %d, value: %s\n", it->first, it->second.c_str());
    printf("\n");

    // 当map中有这个关键字时,insert操作是插入数据不了的,但是用数组方式就不同了,它可以覆盖以前该关键字对应的值
    map<int, string> mapStudent3;
    pair<map<int, string>::iterator, bool> Insert_Pair;
    Insert_Pair = mapStudent3.insert(pair<int, string>(1, "student_one"));
    if (Insert_Pair.second == true)
        cout << "Insert Successfully" << endl;
    else
        cout << "Insert Failure" << endl;

    Insert_Pair = mapStudent3.insert(pair<int, string>(1, "student_two"));
    if (Insert_Pair.second == true)
        cout << "Insert Successfully" << endl;
    else
        cout << "Insert Failure" << endl;
    map<int, string>::iterator iter;
    for (iter = mapStudent3.begin(); iter != mapStudent3.end(); iter++)
        cout << iter->first << ' ' << iter->second << endl;
    printf("\n");

    /**
     * 两种map自定义比较方法
     * Mode == 0 小于号 < 重载
     * Mode == 1 仿函数的应用，这个时候结构体中没有直接的小于号重载
     */
    if (Mode == 0)
    {
        typedef struct tagStudentinfo
        {
            int niD;
            string strName;
            bool operator<(tagStudentinfo const &_A) const
            { // 这个函数指定排序策略，按niD排序，如果niD相等的话，按strName排序
                if (niD < _A.niD)
                    return true;
                if (niD == _A.niD)
                    return strName.compare(_A.strName) < 0;
                return false;
            }
        } Studentinfo, *PStudentinfo; // 学生信息

        int nSize; // 用学生信息映射分数
        map<Studentinfo, int> mapStudent4;
        Studentinfo studentinfo;
        studentinfo.niD = 1;
        studentinfo.strName = "student_one";
        mapStudent4.insert(pair<Studentinfo, int>(studentinfo, 90));
        studentinfo.niD = 2;
        studentinfo.strName = "student_two";
        mapStudent4.insert(pair<Studentinfo, int>(studentinfo, 80));
        LOG_D("operator <\n");
        for (map<Studentinfo, int>::iterator iter = mapStudent4.begin(); iter != mapStudent4.end(); iter++)
            cout << iter->first.niD << ' ' << iter->first.strName << ' ' << iter->second << endl;
    }
    else if (Mode == 1)
    {
        typedef struct tagStudentinfo
        {
            int niD;
            string strName;
        } Studentinfo, *PStudentinfo; // 学生信息

        class Cmp
        {
        public:
            bool operator()(Studentinfo const &_A, Studentinfo const &_B) const
            {
                if (_A.niD < _B.niD)
                    return true;
                if (_A.niD == _B.niD)
                    return _A.strName.compare(_B.strName) < 0;
                return false;
            }
        };

        // 用学生信息映射分数
        multimap<Studentinfo, int, Cmp> mapStudent;
        Studentinfo studentinfo;
        studentinfo.niD = 1;
        studentinfo.strName = "student_one";
        mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));
        studentinfo.niD = 2;
        studentinfo.strName = "student_two";
        mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));
        LOG_D("operator ()\n");
        for (map<Studentinfo, int>::iterator iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
            cout << iter->first.niD << ' ' << iter->first.strName << ' ' << iter->second << endl;
    }

    /**
     * unordered_map 与 map
     * c++11中引入了 unordered_map
     * map底层采用的是红黑树的实现查询的时间复杂度为O(logn) unordered_map的效率在很大的程度上由它的hash函数算法决定
     * unordered_map的底层采用哈希表的实现，查询的时间复杂度为是O(1)
     * unordered_map内部就是无序
     * unordered_map属于关联式容器，采用std::pair保存key-value形式的数据
     * 应用场景：
     *      如果你需要对map中的数据排序，就首选map， 他会把你的数据按照key的自然排序排序（由于它的底层实现红黑树机制所以会排序）
     *      如果不需要排序，就看你对内存和cpu的选择了，不过一般都会选择unordered_map，它的查找效率会更高。
     */
}