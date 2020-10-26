/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// DP 
// 动态规划O(n^2)算法复杂度相比于递归的指数级复杂度要好很多
class Solution
{
public:
    int integerBreak(int n)
    {
        assert(n >= 2);
        vector<int> memo(n + 1, -1);

        for (int i = 2; i <= n; i++)
        {
            // 求解memo, j + (i - j)
            for (int j = 1; j < i; j++)
            {
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }
        }

        return memo[n];
    }

private:
    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }
};

// 递归
class Solution
{
public:
    int integerBreak(int n)
    {
        memo = vector<int>(n + 1, -1);
        return BreakInteger(n);
    }

private:
    vector<int> memo;

    // 将n分割成（至少分割两部分），可以获得的最大面积
    int BreakInteger(int n)
    {
        if (n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        int res = -1;
        for (int i = 1; i < n; i++)
        {
            // 分成res, i*(n-i), i*BreakInteger(n - i)
            if (memo[n - i] == -1)
                res = max3(res, i * (n - i), i * BreakInteger(n - i));
            else
                res = max3(res, i * (n - i), i * memo[n - i]);
        }

        memo[n] = res;
        return res;
    }

    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }
};
// @lc code=end
