/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.82%)
 * Likes:    940
 * Dislikes: 0
 * Total Accepted:    173K
 * Total Submissions: 358K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        memo = vector<int>(n + 1, -1);
        return CalcuWays(n);
    }

private:
    vector<int> memo;

    int CalcuWays(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (memo[n] == -1)
            memo[n] = CalcuWays(n - 1) + CalcuWays(n - 2);
        return memo[n];
    }
};

/*
 * 思考：
 * 只可能从第i-2阶或者第i-1阶到第i阶，到第i阶的状态与第i-3阶没有关系
 * 
 * 所以：
 * 第i阶的爬法数量 = 第i-1阶的爬法数量 + 第i-2阶的爬法数量 
 */

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 超时，错误解法
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n == 1 || n == 2)
//         {
//             return n;
//         }
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };
// @lc code=end
