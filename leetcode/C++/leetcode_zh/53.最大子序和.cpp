/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.08%)
 * Likes:    1834
 * Dislikes: 0
 * Total Accepted:    206.3K
 * Total Submissions: 410.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

/*
 * 动态规划原理：
 * 
 * 1.确认原问题和子问题：
 * 原问题：求n数组的最大连续子数组
 * 子问题：求[0], [0, 1], [1, 2], [0, 1, 2],[2, 3], [1, 2, 3], [0, 1, 2, 3]...中的最大子数组
 * 2.确认i时刻状态：
 * 第i个状态（dp[i]）即为：以第i个数字结尾的最大子段和（最优解）
 * 且，以第i-1个数字结尾的最大子段（dp[i-1]）和与nums[i]相邻
 * 3.确认起始边界状态(i=0,1,2...)的值：
 * 第1个状态i=0为nums[0]
 * 第2个状态i=1为max(dp[0] + nums[i], nums[i])
 * 4.确定状态转移方程：
 * dp[i] = max(dp[i-1] + nums[i], nums[i])
 * 
 */

/*
 * 举例：[-2, -3, 4, -1, 2, 1, -5, 4]
 * i=0: [-2]，                  最大子串：[-2]，            和：-2, dp = -2
 * i=1: [-2， -3]，             最大子串：[-2]，            和：-2, dp = -2 
 * i=2: [-2， -3， 4,]，        最大子串：[4]，             和：4, dp = 4
 * i=3: [-2, -3, 4, -1,]，      最大子串：[4]，             和：4, dp = max(4 - 1, -1) = 3
 * i=4: [-2, -3, 4, -1, 2]，    最大子串：[4， -1， 2]，    和：5, dp = max(3 + 2, 2) = 5
 * i=5: [-2, -3, 4, -1, 2， 1]，最大子串：[4， -1， 2， 1]，和：6,d p = max(5 + 1, 1) = 6
 * 
 */

class Solution
{
public:
    // 暴力搜索 Time limit Exceed
    // int maxSubArray(vector<int> &nums)
    // {
    //     int maxValue = INT_MIN;
    //     for (int i; i < nums.size(); ++i)
    //     {
    //         int sum = 0;
    //         for (int j = i; j < nums.size(); ++j)
    //         {
    //             sum += nums[j];
    //             maxValue = max(sum, maxValue);
    //         }
    //     }
    //     return maxValue;
    // }

    // DP
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_res = max(dp[i], max_res);
        }
        return max_res;
    }

    // // 贪心
    // int maxSubArray(vector<int> &nums)
    // {
    //     //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
    //     int result = INT_MIN;
    //     int numsSize = int(nums.size());
    //     int sum = 0;
    //     for (int i = 0; i < numsSize; i++)
    //     {
    //         sum += nums[i];
    //         result = max(result, sum);
    //         //如果sum < 0，重新开始找子序串
    //         if (sum < 0)
    //         {
    //             sum = 0;
    //         }
    //     }
    //     return result;
    // }

    // int maxSubArray(vector<int> &nums)
    // {
    //     if (nums.empty())
    //     {
    //         return NULL;
    //     }
    //     int maxValue = nums[0];
    //     int currentSum = nums[0];
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         if (currentSum < 0)
    //         {
    //             currentSum = nums[i];
    //         }
    //         else
    //         {
    //             currentSum += nums[i];
    //         }
    //         maxValue = max(currentSum, maxValue);
    //     }
    //     return maxValue;
    // }

    // 分治 divide and conquer
    // int maxSubArray(vector<int> &nums)
    // {

    // }
};
// @lc code=end
