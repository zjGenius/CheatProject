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