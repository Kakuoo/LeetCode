/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// DP 256ms
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// 递归回溯 300ms
class Solution
{
public:
    int numSquares(int n)
    {
        memo = vector<int>(n + 1, -1);
        memo[0] = 0;

        return NumSquaresHelper(n);
    }

private:
    vector<int> memo;
    int NumSquaresHelper(int n)
    {
        if (n == 0)
            return 0;

        int count = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            if (memo[n - i * i] == -1)
                count = min(count, NumSquaresHelper(n - i * i) + 1);
            else
                count = min(count, memo[n - i * i] + 1);
        }
        memo[n] = count;
        return count;
    }
};

// BFS  144ms
class Solution
{
public:
    int numSquares(int n)
    {
        queue<int> Q;
        // vector<int> visited(n + 1, -1);
        int level = 0;

        Q.push(n);
        while (!Q.empty())
        {
            level++;  // 开始生成下一层
            int q_size = Q.size();

            for (int i = 0; i < q_size; i++)
            {
                int curr = Q.front();
                Q.pop();

                // 依次减去1, 4, 9...
                for (int j = 1; j * j <= curr; j++)
                {
                    int next = curr - j * j;
                    if (next == 0)
                        return level;
                        
                    Q.push(next);                    
                }
            }
        }
        return -1;
    }
};
// @lc code=end
