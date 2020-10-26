/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.94%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 198.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 *  
 */

// @lc code=start
#include <vector>
using namespace std;

/* 二分查找

 * 方法一：
 * 使用二分查找法，分别找出区间的左、右端点
 * 
 * 方法二：
 * 使用二分查找法，找到target目标，然后在target目标处向前向后遍历搜索与target不相等的点
 * 
 */

// 方法一 二分查找
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }

    int left_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                if (mid == 0 || target > nums[mid - 1]) // nums[mid-1]可能越界，所以需要前面加上“或”的条件判断是否为特殊情况
                {
                    return mid;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                begin = mid + 1;
            }
        }
        return -1;
    }

    int right_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2; 
            if (target == nums[mid])
            {
                if (mid == nums.size() - 1 || target < nums[mid + 1]) // nums[mid+1]可能越界，所以需要前面加上“或”的条件判断是否为特殊情况
                {
                    return mid;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                begin = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
