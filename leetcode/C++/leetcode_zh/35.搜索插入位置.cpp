/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    136.3K
 * Total Submissions: 300.5K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto first = nums.begin();
        auto last = nums.end();
        while (first < last)
        {
            auto mid = first + ((last - first) >> 1);
            if (*mid < target)
            {
                first = mid + 1;
            }
            else
            {
                last = mid;
            }
        }

        return first - nums.begin();
    }
};


// 方法一 暴力搜索
// 但是对于特别长的nums数组，可能时间复杂度更高，不合理，应采用二分查找
// class Solution
// {
// public:
//     int searchInsert(vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (target <= nums[i])
//             {
//                 return i;
//             }
//         }
//         return nums.size();
//     }
// };



// 方法二 二分查找
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while (index == -1)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                index = mid;
                return index;
            }
            else if (target < nums[mid])
            {
                if (target <= nums[begin])
                {
                    index = begin;
                }
                else /*(target > nums[begin] &&  target < nums[mid])*/
                {
                    end = mid - 1;
                }
            }
            else if (target > nums[mid])
            {
                if (mid == nums.size() - 1 || target <= nums[mid + 1]) // 特殊情况 nums = [1]，输入2时，此时mid==end，或者mid==nums.size()-1
                {
                    index = mid + 1;
                }
                else if (target < nums[end]) /* (target > nums[mid + 1] && target < nums[end]) */
                {
                    begin = mid + 1;
                }
                else if (target == nums[end])
                {
                    index = end;
                }
                else if (target > nums[end])
                {
                    index = end + 1;
                }
            }
        }
        return index;
    }
};

// 二分查找
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 使用二分查找，复杂度更低
        int index = -1;  // 最终返回的下标，若找到该元素下标，否则为需要插入的位置
        int begin = 0;
        int end = nums.size() - 1;
        while (index == -1)  // 若index == -1，说明还未找到正确位置，持续二分搜索
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                index = mid;
            }
            else if (target < nums[mid])
            {
                if (mid == 0 || target > nums[mid - 1])
                {
                    index = mid;
                }
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                if (mid == nums.size() - 1 || target < nums[mid + 1])
                {
                    index = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return index;
    }
};
// @lc code=end
