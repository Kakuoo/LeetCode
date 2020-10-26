/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        long long res = 0;
        int state = 0;
        for (char ch : str)
        {
            if (state == 0 && ch == ' ')
                continue;
            else if (state == 0 && ch == '+')
                state = 1;
            else if (state == 0 && ch == '-')
                state = 2;
            else if (ch >= '0' && ch <= '9')
            {
                if (state == 0)
                    state = 1;
                int tmp = ch - '0';
                res = res * 10 + tmp;
                if (res > INT_MAX)
                    break;
            }
            else
                break;
        }

        if (state == 1 && res > INT_MAX)
            res = INT_MAX;
        else if (state == 2)
        {
            res = -res;
            if (res < INT_MIN)
                res = INT_MIN;
        }

        return res;
    }
};
// @lc code=end
