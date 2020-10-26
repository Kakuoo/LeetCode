/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    // 贪心
    // int jump(vector<int> &nums)
    // {
    //     if (nums.size() < 2)
    //     {
    //         return 0;
    //     }
    //     int cur_max_index = nums[0];
    //     int pre_max_index = nums[0];
    //     int jump_min = 1;

    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         if (i > cur_max_index)
    //         {
    //             jump_min++;
    //             cur_max_index = pre_max_index;
    //         }
    //         if (pre_max_index < nums[i] + i)
    //         {
    //             pre_max_index = nums[i] + i;
    //         }
    //     }
    //     return jump_min;
    // }

    // 贪心
    int jump(vector<int> &nums)
    {
        int farthest = 0, end = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(nums[i] + i, farthest);
            if (end == i)
            {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }

    // 动态规划
    // vector<int> memo;
    // int jump(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     memo = vector<int>(n, n);
    //     return dp(nums, 0);
    // }

    // int dp(vector<int> &nums, int p)
    // {
    //     int n = nums.size();
    //     if (p >= n - 1)
    //     {
    //         return 0;
    //     }
    //     if (memo[p] != n)
    //     {
    //         return memo[p];
    //     }
    //     int setps = nums[p];
    //     for (int i = 0; i < setps; i++)
    //     {
    //         int subProblem = dp(nums, p + i);
    //         memo[p] = min(memo[p], subProblem + 1);
    //     }
    //     return memo[p];
    // }
};
// @lc code=end
