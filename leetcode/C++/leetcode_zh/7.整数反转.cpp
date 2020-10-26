/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long n = 0;
        while (x)
        {
            n = n * 10 + x % 10;
            x /= 10;
        }

        return n > INT_MAX || n < INT_MIN ? 0 : n;
    }
};
// @lc code=end
