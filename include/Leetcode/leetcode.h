#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include <iostream>
#include <vector>

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
};

#endif // !_LEETCODE_H_