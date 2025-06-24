#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include <iostream>
#include <vector>
#include <set>
#include <bitset>

class LeedCode
{
private:
public:
    LeedCode();
    ~LeedCode();
    void topic_1(std::vector<int> &nums, int target);
    bool topic_20(std::string s);
    int topic_27(std::vector<int> &nums, int val);
    std::vector<int> topic_2682(int n, int k);
    bool topic_9(int n);
    int topic_575(std::vector<int>& candyType);
    std::vector<std::string> topic_0807(std::string S);
    std::vector<int> topic_1103(int candies, int num_people);
    int topic_1334(int n, std::vector<std::vector<int>> &edges, int distanceThreshold);
    bool topic_292(int n);
    bool topic_3127(std::vector<std::vector<char>> &grid);
    std::vector<int> topic_2200(std::vector<int>& nums, int key, int k);
};

#endif // !_LEETCODE_H_