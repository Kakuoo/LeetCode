/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>
#include <functional>
using namespace std;

// 条件中c在前，44ms runtime 6.11%
// 条件中c在后，20ms runtime 24.67%
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res = "";
        int curr = 0;
        string::reverse_iterator it1 = num1.rbegin();
        string::reverse_iterator it2 = num2.rbegin();

        while (it1 != num1.rend() || it2 != num2.rend() || curr != 0)
        {
            if (it1 != num1.rend())
            {
                curr += *it1 - '0';
                it1++;
            }
            if (it2 != num2.rend())
            {
                curr += *it2 - '0';
                it2++;
            }

            res.insert(0, 1, curr % 10 + '0');
            curr = curr / 10;
        }
        return res;
    }
};

// 经典方法 8ms runtime 62.35%
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.empty() || num2.empty())
            return "";

        string res = "";
        int curr = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || curr != 0)
        {
            if (i >= 0)
                curr += num1[i--] - '0';
            if (j >= 0)
                curr += num2[j--] - '0';

            res += to_string(curr % 10);
            curr /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
        // return string(res.rbegin(), res.rend());
    }
};

// 精简版 24ms  20.07%
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res;
        char c = 0;
        auto i = num1.rbegin();                           // string::reverse_iterator
        auto j = num2.rbegin();                           // string::reverse_iterator
        while (i != num1.rend() || j != num2.rend() || c) // 条件包含c很重要
        {
            char ch = c;
            if (i != num1.rend())
                ch += *(i++) - '0';
            if (j != num2.rend())
                ch += *(j++) - '0';
            c = ch / 10;
            res.insert(0, 1, ch % 10 + '0');
        }
        return res;
    }
};
// @lc code=end
