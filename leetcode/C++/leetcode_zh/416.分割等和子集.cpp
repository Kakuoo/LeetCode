/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
#include <cassert>
using namespace std;

// DP 二维数组
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // if (nums.size() == 1)
        //     return false;

        int sum = 0;
        for (int e : nums)
            sum += e;

        if (sum & 1)
            return false;

        int n = nums.size();
        int C = sum / 2;
        // vector<bool> dp(C + 1, false);
        vector<vector<bool>> dp(n, vector<bool>(C + 1, false));

        // 第一行
        for (int j = 0; j <= C; j++)
        {
            dp[0][j] = (nums[0] == j);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= C; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[n - 1][C];
    }
};

// DP 一位数组，只维护一行数据
// 二维数组，行为[1, 5, 5, 11],列为[0, 1, ..., 11]，其中11为分组的和sum/2，即为背包问题中的C容量
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
            return false;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        int n = nums.size();
        int C = sum / 2;
        vector<bool> dp(C + 1, false);

        // 第一行
        for (int j = 0; j <= C; j++)
        {
            dp[j] = (nums[0] == j);
        }

        // 第二到第n行
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = C; j >= nums[i]; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[C];
    }
};

// 递归 + 记忆化搜索
    class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
            return false;

        int sum = 0;
        for (int e : nums)
        {
            assert(e > 0);
            sum += e;
        }

        if (sum % 2 != 0)
            return false;

        memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        return TryPartition(nums, nums.size() - 1, sum / 2);
    }

private:
    // memo[i][c]表示使用索引为[0,...i]的元素，是否可以完全填充一个容量为C的背包
    // -1表示为未计算，0表示不可以完全填充，1表示可以完全填充
    vector<vector<int>> memo;

    bool TryPartition(const vector<int> &nums, int index, int target)
    {
        if (target == 0)
            return true;

        if (index < 0 || target < 0)
            return false;

        if (memo[index][target] != -1)
            return memo[index][target] == 1;

        bool flag = TryPartition(nums, index - 1, target) ||
                    TryPartition(nums, index - 1, target - nums[index]);
        memo[index][target] = flag ? 1 : 0;
        return memo[index][target] == 1;
    }
};
// @lc code=end
