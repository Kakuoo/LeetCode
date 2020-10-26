/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start

#include <vector>
#include <string>
using namespace std;


// 贪心
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> S;
        string result = "";
        for (int i = 0; i < num.length(); i++)
        {
            int number = num[i] - '0';

            while (S.size() != 0 && k > 0 && S.back() > number)
            {
                S.pop_back();
                k--;
            }
            if (number != 0 || S.size() != 0) // 将数字添入栈中
            {
                S.push_back(number);
            }
        }
        while (S.size() != 0 && k > 0) // 如果栈不空，且可以继续删除
        {
            S.pop_back();
            k--;
        }
        for (int i = 0; i < S.size(); i++) // 遍历栈中元素，存储至result
        {
            result.append(1, S[i] + '0');
        }
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
};
// @lc code=end
