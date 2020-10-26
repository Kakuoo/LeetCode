/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.97%)
 * Likes:    646
 * Dislikes: 0
 * Total Accepted:    88.4K
 * Total Submissions: 200.2K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

// LIS(i) 表示以第i个数字为结尾的最长上升子序列的长度
// LIS(i) 表示从[0, ..., i]范围内，选择数字nums[i]可以获得的最长上升子序列的长度
// LIS(i) = max(1 + LIS(j) if nums[i] > nums[j])，其中 j < i
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        // 初始化时每个数字的最长子序列就是自己本身，值为1
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int res = 1;
        for (int e : dp)
        {
            res = max(res, e);
        }

        return res;
    }
};

/*
 * 思考：
 * 1.若第i个状态代表前i个数字中最长上升子序列的长度
 * 2.若第i个状态代表以第i个数字为结尾的最长上升子序列的长度
 *  则最终结果为dp[0],dp[1],dp[2]...dp[n-1]中的最大值
 * 
 */
// 复杂度O(n^2), medium
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    // 说明nums[i]可以放置在nums[j]的后面，组成最长上升子序列
                    dp[i] = dp[j] + 1;
                }
            }
            LIS = max(LIS, dp[i]);
        }
        return LIS;
    }
};

/*
 * 设置一个栈（使用vector实现）stack，stack[i]代表长度为i+1的上升子序列的
 * 最后一个元素的最小可能取值
 * 
 * 例如：[1,3,2,3,1,4]
 * 长度为1的上升子序列[1],[2],[3],[4]，则stack[0] = 1
 * 长度为2的上升子序列[1,2],[1,3],[1,4][2,3],[2,4],[3,4] 则stack[1] = 2
 * 长度为3的上升子序列[1,2,3],[1,3,4],[2,3,4]，则stack[2] = 3
 * 长度为4的上升子序列[1,2,3,4]，则stack[3] = 4
 * ......
 * 则最后栈的大小，就是记录的最长的上升子序列的长度
 * 
 */

// 复杂度O(nlogn)), hard
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > stack.back())
            {
                stack.push_back(nums[i]);
            }
            else
            {
                // 复杂度O(nlogn) 二分搜索
                // int pos = BinarySearch(stack, nums[i]);
                // stack[pos] = nums[i];

                // 复杂度O(n^2)
                for (int j = 0; j < stack.size(); ++j)
                {
                    if (stack[j] >= nums[i]) // 此处必须要大于等于，否则无法全部样例AC
                    {
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }

private:
    int BinarySearch(vector<int> &nums, int target)
    {
        int pos = -1;
        int begin = 0;
        int end = nums.size();
        while (pos == -1)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                pos = mid;
            }
            else if (target < nums[mid])
            {
                if (mid == 0 || target > nums[mid - 1])
                {
                    pos = mid;
                }
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                if (mid == nums.size() - 1 || target < nums[mid + 1])
                {
                    pos = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return pos;
    }
};
// @lc code=end
