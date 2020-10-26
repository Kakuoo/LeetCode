/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (42.89%)
 * Likes:    746
 * Dislikes: 0
 * Total Accepted:    101.1K
 * Total Submissions: 228.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */

// @lc code=start

/*
 * 动态规划原理：
 * 
 * 1.确认原问题和子问题：
 * 原问题：求n个房间的最优解
 * 子问题：求前1个房间、前2个房间...前n-1个房间的最优解
 * 2.确认状态：
 * 第i个状态为前i个房间能够获取的最大财宝（最优解）
 * 3.确认边界状态的值：
 * 前1个房间的最优解：第1个房间的财宝
 * 前2个房间的最优解：第1、2个房间中有较大财宝数的房间
 * 4.确定状态转移方程：
 * a.选择第i个房间： 第i个房间 + 前i-2个房间的最优解
 * b.不选择第i个房间：前i-1个房间的最优解
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i]); (i >= 3)
 * 
 */


/*
    对状态的定义：
    1.考虑偷取[x, ..., n - 1]范围内的房子
    2.考虑偷取[0, ..., x]范围内的房子
*/

#include <vector>
using namespace std;

// DP
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = 0; // 记录不抢夺i-1房屋的最大利润 
        int curr = 0; // 记录抢夺i-1房屋的收益
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        // memo[i] 表示考虑抢劫 nums[i, ..., n-1] 范围内所能获得的最大收益
        vector<int> memo(n, -1);
        memo[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                memo[i] = max(memo[i], nums[j] + memo[j + 2]);
            }
        }
        return memo[0];
    }
};

// DP 4ms
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1) // 为防止dp[1]赋值错误
            return nums[0];

        // dp[i] 表示考虑抢劫 nums[i, ..., n-1] 范围内所能获得的最大收益
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

// 递归 + 记忆化搜索, Time Limited Exceeded
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        memo = vector<int>(nums.size(), -1);
        return TryRob(nums, 0);
    }

private:
    vector<int> memo;

    // 考虑抢劫 nums(index, ... nums.size()) 这个范围内的所有房子
    int TryRob(vector<int> &nums, int index)
    {
        if (index >= nums.size())
            return 0;

        if (memo[index] != -1)
            return memo[index];

        int res = 0;
        for (int i = index; i < nums.size(); i++)
        {
            // if (memo[index] == -1)
            res = max(res, nums[i] + TryRob(nums, i + 2));
            // else
            // res = max(res, nums[i] + memo[i + 2]);
        }

        return res;
    }
};
// @lc code=end
