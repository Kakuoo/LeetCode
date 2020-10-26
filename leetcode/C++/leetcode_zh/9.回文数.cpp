/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long tmp = x;
        long reversed = 0;
        while (tmp)
        {
            reversed = reversed * 10 + tmp % 10;
            tmp = tmp / 10;
        }

        return reversed == x; 
    }
};
// @lc code=end
