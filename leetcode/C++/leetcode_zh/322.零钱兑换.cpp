/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.43%)
 * Likes:    552
 * Dislikes: 0
 * Total Accepted:    75.7K
 * Total Submissions: 194.3K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
/*
 * 特殊情况在于可能有非整数倍的硬币面值，例如[1,2,5,7,10]
 * 动态规划原理：
 * 
 * 1.确认原问题和子问题：
 * 2.确认i时刻状态：
 * dp[i]代表金额i的最优解   
 * 3.确认起始边界状态(i=0,1,2...)的值：
 * 4.确定状态转移方程：
 * 状态i可由状态i-1, i-2, i-5, i-7, i-10等状态推出
 * dp[i] = min(dp[i-1], dp[i-2], dp[i-5], dp[i-7], dp[i-10]) + 1
 */

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);   // 最初所有金额均为-1，不可达到
        dp[0] = 0;                        // 金额0为最优解
        for (int i = 1; i <= amount; ++i) // 循环各个面值，找到dp[i]最优解
        {
            // i代表金额，coin[j]代表第j个钱币的面值
            for (int j = 0; j < coins.size(); ++j)
            {
                // i - coin[j]>=0说明当前金额i大于coin[j]这个面值的钱币，即包含关系
                // dp[i - coins[j]] != -1 说明剩余金额之间的差价可以被最优解补齐
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) // 说明何时更新dp[i]，使dp[i]最小
                    {
                        dp[i] = dp[i - coins[j]] + 1; // 递推公式
                    }
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end
