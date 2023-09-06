/**
 * @file container.cpp
 * @author zhangjun
 * @brief 容器的使用
 * @version 0.1
 * @date 2023-06-12
 *
 * @copyright Copyright (c) 2023
 * 参考链接:
 * https://blog.csdn.net/u010183728/article/details/81913729
 *
 * 代办:
 *  spdlog 日志,后续查看一下
 */
#include "container.h"

void printfDeque(const deque<int> &que)
{
    for (deque<int>::const_iterator it = que.begin(); it != que.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/**
 * @brief deque队列的测试程序
 *
 */
void deque_test()
{
    cout << "deque学习" << endl;
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

    deque<int> assginDeque;
    // 赋值操作
    assginDeque.assign(q.begin(), q.end());
    printfDeque(assginDeque);

    assginDeque.push_front(1);
    assginDeque.push_back(11);
    printfDeque(assginDeque);
}

int fun(int acc, int num)
{
    return acc + num * 3;
}
/**
 * @brief list的测试程序
 * 优点：采用动态存储分配，不会造成内存浪费和溢出；链表插入和删除方便
 * 缺点：空间（指针域）和时间（遍历）花费比较大
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
 * @brief map的测试程序     不推荐用map[key] = value;方式赋值
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

// 仿函数
class CompareSet
{
public:
    // 从大到小排序
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
    // 从小到大排序
    // bool operator()(int v1, int v2)
    //{
    //     return v1 < v2;
    // }
};

/* Person类，用于test03 */
class Person
{
    friend ostream &operator<<(ostream &out, const Person &person);

public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

    bool operator==(const Person &p)
    {
        if (this->mName == p.mName && this->mAge == p.mAge)
            return true;
        else
            return false;
    }

public:
    string mName;
    int mAge;
};

/* 仿函数ComparePerson,用于test03 */
class ComparePerson
{
public:
    // 名字大的在前面，如果名字相同，年龄大的排前面
    bool operator()(const Person &p1, const Person &p2)
    {
        if (p1.mName == p2.mName)
        {
            return p1.mAge > p2.mAge;
        }
        return p1.mName > p2.mName;
    }
};

ostream &operator<<(ostream &out, const Person &person)
{
    out << "name:" << person.mName << " age:" << person.mAge << endl;
    return out;
}

/* 打印set类型的函数模板 */
template <typename T>
void PrintSet(T &s)
{
    for (typename T::iterator iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

/**
 * @brief set/multiset multiset可以插入重复数据
 * std::set 是关联容器，含有 Key 类型对象的已排序集*
 * set 通常以红黑树实现。
 * set中的元素即是键值又是实值，set不允许两个元素有相同的键值。
 * 不能通过set的迭代器去修改set元素，原因是修改元素会破坏set组织。当对容器中的元素进行插入或者删除时，操作之前的所有迭代器在操作之后依然有效。
 * set和multiset的底层实现是一种高效的平衡二叉树，即红黑树（Red-Black Tree）
 * set常用成员函数:
        begin()--返回指向第一个元素的迭代器
        clear()--清除所有元素
        count()--返回某个值元素的个数
        empty()--如果集合为空，返回true
        end()--返回指向最后一个元素的迭代器
        equal_range()--返回集合中与给定值相等的上下限的两个迭代器
        erase()--删除集合中的元素
        find()--返回一个指向被查找到元素的迭代器
        get_allocator()--返回集合的分配器
        insert()--在集合中插入元素
        lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
        key_comp()--返回一个用于元素间值比较的函数
        max_size()--返回集合能容纳的元素的最大限值
        rbegin()--返回指向集合中最后一个元素的反向迭代器
        rend()--返回指向集合中第一个元素的反向迭代器
        size()--集合中元素的数目
        swap()--交换两个集合变量
        upper_bound()--返回大于某个值元素的迭代器
        value_comp()--返回一个用于比较元素间的值的函数
 */
void set_test(int Mode)
{
    if (Mode == 0)
    {
        // set容器默认从小到大排序
        set<int> s;
        s.insert(10);
        s.insert(20);
        s.insert(30);

        // 输出set
        PrintSet(s);
        // 结果为:10 20 30

        /* set的insert函数返回值为一个对组(pair)。
           对组的第一个值first为set类型的迭代器：
           1、若插入成功，迭代器指向该元素。
           2、若插入失败，迭代器指向之前已经存在的元素
           对组的第二个值seconde为bool类型：
           1、若插入成功，bool值为true
           2、若插入失败，bool值为false
        */
        pair<set<int>::iterator, bool> ret = s.insert(40);
        if (true == ret.second)
            cout << *ret.first << " 插入成功" << endl;
        else
            cout << *ret.first << " 插入失败" << endl;
    }
    else if (Mode == 1)
    {
        /* 如果想让set容器从大到小排序，需要给set容
           器提供一个仿函数,本例的仿函数为CompareSet
        */
        set<int, CompareSet> s;
        s.insert(10);
        s.insert(20);
        s.insert(30);

        // 打印set
        PrintSet(s);
    }
    else if (Mode == 2)
    {
        /* set元素类型为Person，当set元素类型为自定义类型的时候
           必须给set提供一个仿函数，用于比较自定义类型的大小，
           否则无法通过编译
        */
        set<Person, ComparePerson> s;
        s.insert(Person("John", 22));
        s.insert(Person("Peter", 25));
        s.insert(Person("Marry", 18));
        s.insert(Person("Peter", 36));

        // 打印set
        PrintSet(s);
    }
}

struct Employees
{
    string name;
    int salary;
};

/**
 * @brief STL学习 员工分组
 * 描述：
 * 公司招聘10名员工(ABCDEFGHIJ),需要指派员工到部门工作
 * 员工信息：姓名 薪水 ； 部门： 策划、美术、研发
 * 随机给员工分配部门和工资
 * 通过multimap进行信息的插入 key(部门编号) value(员工)
 * 分部门显示员工信息
 *
 * 实现步骤
 * 创建10名员工，放到vector
 * 遍历vector容器，进行 随机分组
 * 分组后，员工部门编号作为key，具体员工信息作为value，放入multimap容器中
 * 分部门显示员工信息
 */
void STL_test()
{
    cout << endl
         << "案例情景" << endl;
    srand(time(NULL)); // 随机种子

    // 添加员工并随机分配薪水
    char original_employee[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    vector<Employees> employees;
    for (int i = 0; i < sizeof(original_employee) / sizeof(char); i++)
    {
        Employees e;
        e.name = original_employee[i];
        e.salary = rand() % 6000 + 4001;
        employees.push_back(e);
    }
    cout << "员工个数 " << employees.size() << endl;

    multimap<string, Employees> company;
    for (int i = 0; i < employees.size(); i++)
    {
        int select = rand() % 3;
        if (select == 0)
        {
            company.insert(make_pair("策划部", employees[i]));
        }
        else if (select == 1)
        {
            company.insert(make_pair("美术部", employees[i]));
        }
        else if (select == 2)
        {
            company.insert(make_pair("研发部", employees[i]));
        }
    }

    multimap<string, Employees>::iterator Company_it;
    pair<multimap<string, Employees>::iterator, multimap<string, Employees>::iterator> ret;

    ret = company.equal_range("美术部");
    cout << "美术部" << endl;
    for (Company_it = ret.first; Company_it != ret.second; ++Company_it)
    {
        cout << "姓名:" << (*Company_it).second.name << " "
             << "薪水:" << (*Company_it).second.salary << endl;
    }
    cout << endl;
    ret = company.equal_range("策划部");
    cout << "策划部" << endl;
    for (Company_it = ret.first; Company_it != ret.second; ++Company_it)
    {
        cout << "姓名:" << (*Company_it).second.name << " "
             << "薪水:" << (*Company_it).second.salary << endl;
    }
    cout << endl;
    ret = company.equal_range("研发部");
    cout << "研发部" << endl;
    for (Company_it = ret.first; Company_it != ret.second; ++Company_it)
    {
        cout << "姓名:" << (*Company_it).second.name << " "
             << "薪水:" << (*Company_it).second.salary << endl;
    }
    cout << endl;
}

/**
 * @brief 返回值是bool的数据类型，称为谓词
 */
class OverFive_Int
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
/**
 * @brief 一元谓词学习
 */
void predicateOne_test()
{
    cout << endl
         << "一元谓词" << endl;
    vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }

    // OverFive_Int()匿名函数对象  find_if()返回的是迭代器
    vector<int>::iterator ret = find_if(vec.begin(), vec.end(), OverFive_Int());

    if (ret == vec.end())
        cout << "没有超过5的数字" << endl;
    else
    {

        cout << "超过5的数字: ";
        for (; ret != vec.end(); ret++)
        {
            cout << *ret << " ";
        }
        cout << endl;
    }
}

/**
 * @brief 返回值是bool的数据类型，称为谓词
 */
class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};
/**
 * @brief 二元谓词学习
 */
void predicateTwo_test()
{
    cout << endl
         << "二元谓词" << endl;
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(45);
    vec.push_back(20);
    vec.push_back(15);
    vec.push_back(60);

    sort(vec.begin(), vec.end());

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 使用函数对象 改变算法策略
    sort(vec.begin(), vec.end(), MyCompare());
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief 内建函数对象 算术仿函数
 *
 * template<class T> bool plus<T>       加法仿函数
 * template<class T> bool minus<T>      减法仿函数
 * template<class T> bool multiplies<T> 乘法仿函数
 * template<class T> bool divides<T>    除法仿函数
 * template<class T> bool modulus<T>    取模仿函数
 * template<class T> bool negate<T>     取反仿函数
 */
void functional_test1()
{
    cout << endl
         << "内建函数对象使用 算术仿函数" << endl;
    // 需要包含头文件 functional
    negate<int> n;

    cout << "取反 " << n(50) << endl;

    plus<int> p;
    cout << "加法 " << p(50, 10) << endl;
}

/**
 * @brief 内建函数对象 关系仿函数
 *
 * template<class T> bool equal_to<T>       等于
 * template<class T> bool not_equal_to<T>   不等于
 * template<class T> bool greater<T>        大于
 * template<class T> bool greater_equal<T>  大于等于
 * template<class T> bool less<T>           小于
 * template<class T> bool less_equal<T>     小于等于
 */
void functional_test2()
{
    cout << endl
         << "内建函数对象使用 关系仿函数" << endl;
    // 需要包含头文件

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(45);
    vec.push_back(20);
    vec.push_back(15);
    vec.push_back(60);

    // sort()底层使用的是less<T>()
    sort(vec.begin(), vec.end(), greater<int>());

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/**
 * @brief 内建函数对象 逻辑仿函数
 *
 * template<class T> bool logical_and<T>  逻辑与
 * template<class T> bool logical_or<T>   逻辑或
 * template<class T> bool logical_not<T>  逻辑非
 */
void functional_test3()
{
    cout << endl
         << "内建函数对象使用 逻辑仿函数" << endl;
    // 需要包含头文件

    vector<bool> vec1;
    vec1.push_back(true);
    vec1.push_back(false);
    vec1.push_back(false);
    vec1.push_back(true);
    vec1.push_back(false);

    for (vector<bool>::iterator it = vec1.begin(); it != vec1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 运用逻辑非 将容器vec1搬运到vec2中 并执行逻辑非操作
    vector<bool> vec2;
    vec2.resize(vec1.size()); // 这一步需要

    // 需要包含头文件algorithm
    transform(vec1.begin(), vec1.end(), vec2.begin(), logical_not<bool>());

    for (vector<bool>::iterator it = vec2.begin(); it != vec2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class MyPrintInt
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
    void operator()(const Person &val)
    {
        cout << val;
    }
};

class MyAssign
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};

/**
 * @brief 常用的遍历算法
 */
void algorithm_for()
{
    cout << endl
         << "遍历算法 for_each、transform" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    vector<int> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), MyAssign());

    cout << "v1 transform to v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrintInt());
    cout << endl;
}

void algorithm_find()
{
    cout << endl
         << "查找算法 find()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    vector<int>::iterator it1 = find(v1.begin(), v1.end(), 5);
    if (it1 != v1.end())
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);

    vector<Person> v2;

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    cout << "v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrintInt());

    vector<Person>::iterator it2 = find(v2.begin(), v2.end(), p2);
    if (it2 != v2.end())
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;
}

class Over20_Person
{
public:
    bool operator()(const Person &val)
    {
        if (val.mAge > 20)
            return true;
        else
            return false;
    }
};

void algorithm_find_if()
{
    cout << endl
         << "查找算法 find_if()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "内置数据类型v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    vector<int>::iterator it1 = find_if(v1.begin(), v1.end(), OverFive_Int());
    if (it1 != v1.end())
    {
        cout << "找到了" << endl;
        for_each(it1, v1.end(), MyPrintInt());
        cout << endl;
    }
    else
        cout << "没找到" << endl;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);

    vector<Person> v2;

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    cout << "自定义数据类型v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrintInt());

    vector<Person>::iterator it2 = find_if(v2.begin(), v2.end(), Over20_Person());
    if (it2 != v2.end())
    {
        cout << "找到了" << endl;
        for_each(it2, v2.end(), MyPrintInt());
    }
    else
        cout << "没找到" << endl;
}

void algorithm_adjacent_find()
{
    cout << endl
         << "查找算法 adjacent_find()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    vector<int>::iterator it1 = adjacent_find(v1.begin(), v1.end());
    if (it1 != v1.end())
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;
}

void algorithm_binary_search()
{
    cout << endl
         << "查找算法 binary_search()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    bool ret = binary_search(v1.begin(), v1.end(), 5);
    if (ret)
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;
}

void algorithm_count()
{
    cout << endl
         << "查找算法 count()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "内置数据类型v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    int ret1 = count(v1.begin(), v1.end(), 4);
    if (ret1 != 0)
    {
        cout << "存在" << ret1 << "个相同的元素" << endl;
    }
    else
        cout << "不存在相同的元素" << endl;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);
    Person p6("A", 10);

    vector<Person> v2;

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);
    v2.push_back(p6);

    cout << "自定义数据类型v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrintInt());

    int ret2 = count(v2.begin(), v2.end(), p1);
    if (ret2 != 0)
    {
        cout << "存在" << ret2 << "个相同的元素" << endl;
    }
    else
        cout << "不存在相同的元素" << endl;
}

void algorithm_count_if()
{
        cout << endl
         << "查找算法 count_if()" << endl;
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    cout << "内置数据类型v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrintInt());
    cout << endl;

    int ret1 = count_if(v1.begin(), v1.end(), OverFive_Int());
    cout << "存在" << ret1 << "个超过5的元素" << endl;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);

    vector<Person> v2;

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    cout << "自定义数据类型v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrintInt());

    int ret2 = count_if(v2.begin(), v2.end(), Over20_Person());
    cout << "存在" << ret2 << "个年龄超过20的元素" << endl;
}

/**
 * @brief 常见的查找算法
 * find(iterator beg/开始迭代器, iterator end/结束迭代器, value/查找的元素)                                 查找元素
 * find_if(iterator beg/开始迭代器, iterator end/结束迭代器, _Pred/函数或谓词(返回bool类型的仿函数))         按条件查找元素
 * adjacent_find(iterator beg/开始迭代器, iterator end/结束迭代器)                                         查找相邻的重复元素，返回相邻元素第一个位置的迭代器
 * bool binary_search(iterator beg/开始迭代器, iterator end/结束迭代器, value)                             查找指定元素(二分查找法)，查到返回true 注意：需要在有序序列中使用
 * count(iterator beg/开始迭代器, iterator end/结束迭代器, value)                                          统计元素个数 对于自定义数据类型，需要重载operator==
 * count_if(iterator beg/开始迭代器, iterator end/结束迭代器, _Pred/函数或谓词(返回bool类型的仿函数))        按条件统计元素个数
 */
void algorithm_find_example()
{
    // algorithm_find();
    // algorithm_find_if();
    // algorithm_adjacent_find();
    // algorithm_binary_search();
    // algorithm_count();
    algorithm_count_if();
}