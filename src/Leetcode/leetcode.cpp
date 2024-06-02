#include "leetcode.h"
#include <algorithm>
#include <map>
#include <algorithm>
#include <stack>

LeedCode::LeedCode()
{
}

LeedCode::~LeedCode()
{
}

void LeedCode::topic_1(std::vector<int> &nums, int target)
{
    std::map<int, int> num_map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (target < nums[i])
        {
            num_map.insert(std::map<int, int>::value_type(i, nums[i]));
        }
    }

    printf("000 %d\n", num_map.size());

    for (std::map<int, int>::iterator it = num_map.begin(); it != num_map.end(); it++)
    {
        printf("key:%d value:%d ", it->first, it->second);
    }

    int data;

    // for (auto i = num_map.begin(); i != num_map.end(); i++)
    // {
    //     for (auto j = num_map.begin() + i; j != num_map.end(); j++)
    //     {
    //     }
    // }
}

bool LeedCode::topic_20(std::string s)
{
    std::stack<char> stack_s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack_s.push(s[i]);
        else
        {
            if (!stack_s.empty())
            {
                if (s[i] == ')')
                    if (stack_s.top() != '(')
                        return false;
                if (s[i] == ']')
                    if (stack_s.top() != '[')
                        return false;
                if (s[i] == '}')
                    if (stack_s.top() != '{')
                        return false;
            }
            else
                return false;
            stack_s.pop();
        }
    }
    // printf("empty:%d size:%d\n", stack_s.empty(), stack_s.size());
    return stack_s.empty();
}

int LeedCode::topic_27(std::vector<int> &nums, int val)
{
    // printf("1vec size:%d\n", nums.size());
    auto iter = std::remove(nums.begin(), nums.end(), val);
    nums.erase(iter, nums.end()); // 重置vector大小

    for (auto first = nums.begin(); first < iter; ++first)
    {
        std::cout << *first << " ";
    }
    std::cout << std::endl;

    return nums.size();
}

std::vector<int> LeedCode::topic_2682(int n, int k)
{
    // int step = 1;
    // int people = 1;
    // std::map<int, int> num_key;
    // std::vector<int> num_vec;

    // for (int i = 1; i <= n; i++)
    // {
    //     num_key[i] = 0;
    //     // printf("n:%d ", i);
    // }
    // // printf("\n");
    // for (auto it = num_key.begin(); it != num_key.end(); it++)
    // {
    //     printf("key:%d value:%d\n", (*it).first, (*it).second);
    // }

    // while (1)
    // {
    //     printf("people:%d\n", people);
    //     if (num_key[people] == 1)
    //         break;

    //     num_key[people] = 1;

    //     people = step * k + people; //
    //     if (people > n)
    //         people = people % n;
    //     if (people == 0)
    //         people = n;
    //     step++;
    // }

    // for (auto it = num_key.begin(); it != num_key.end(); it++)
    // {
    //     if ((*it).second != 1)
    //     {
    //         num_vec.push_back((*it).first);
    //     }
    //     printf("key:%d value:%d\n", (*it).first, (*it).second);
    // }

    // return num_vec;

    int step = 1;
    int people = 1;
    std::vector<int> num_vec;

    for (int i = 1; i <= n; i++)
    {
        num_vec.push_back(i);
    }

    while (1)
    {
        printf("people:%d\n", people);

        std::vector<int>::iterator iter = std::find(num_vec.begin(), num_vec.end(), people);
        if (iter == num_vec.end())
            return num_vec;
        else
            num_vec.erase(iter);

        people = step * k + people; //
        if (people > n)
            people = people % n;
        if (people == 0)
            people = n;
        step++;
    }
}

bool LeedCode::topic_9(int n)
{
    // std::string str = std::to_string(n);
    // std::string s1(str.rbegin(), str.rend());
    // // printf("s1:%s,s2:%s\n", str.c_str(), s1.c_str());
    // if (str.compare(s1))
    //     return false;

    // return true;

    if (n < 0)
        return false;
    if (n > 1e9 && n % 10 > 2)
        return false;
    int temp1 = n, temp2 = 0;

    while (n)
    {
        temp2 = temp2 * 10 + n % 10;
        n = n / 10;
        printf("n:%d ", n);
    }
    printf("\n");
    printf("temp1:%d temp2:%d\n", temp1, temp2);
    return temp1 == temp2;
}
// 耗时最短的
int distributeCandies_575(std::vector<int>& candyType) {
    std::bitset<200001> bs;
    for(const int& i : candyType){
        bs.set(i + 100000);
    }
    return std::min(bs.count(), candyType.size() / 2);
}
int LeedCode::topic_575(std::vector<int>& candyType) 
{
    if(candyType.size() % 2 != 0)
        return -1;

    int vec_size = candyType.size();
    
    // for(int i = 0; i < candyType.size(); i++)
    // {
    //     printf("%d ", candyType[i]);
    // }
    // printf("\n");

    std::set<int> s(candyType.begin(), candyType.end());
    candyType.assign(s.begin(), s.end());

    // for(int i = 0; i < candyType.size(); i++)
    // {
    //     printf("%d ", candyType[i]);
    // }
    // printf("\n");

    if(candyType.size() >= vec_size / 2)
        return vec_size / 2;
    else
        return candyType.size();
}


std::vector<std::string> LeedCode::topic_0807(std::string S) 
{
    if(S.size() > 1)
    {
        char first_code = S.front();
        printf("first_code-%c\n", first_code);
        std::vector<std::string> ret = topic_0807(S.substr(1, -1));
        std::vector<std::string> temp_s;
        for(int i = 0; i < ret.size(); i++)
        {
            for(int j = 0; j < ret[i].size(); j++)
            {
                std::string str = ret[i];
                str = str.insert(j, 1, first_code);
                printf("str:%s\n", str.c_str());
                temp_s.push_back(str);
            }
            printf("\n");
        }
        return temp_s;
    }
    else
    {
        std::vector<std::string> temp_s = {S};
        printf("--%s\n", S.c_str());
        return temp_s;
    }
}