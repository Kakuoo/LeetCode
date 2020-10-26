/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.39%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 242.6K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

// 旋转数组 性质：nums[begin] > nums[end]
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                if (nums[begin] < nums[mid]) // 说明是递增区间
                {
                    if (target < nums[begin])
                    {
                        begin = mid + 1;
                    }
                    else if (target >= nums[begin])
                    {
                        end = mid - 1;
                    }
                }
                else if (nums[begin] > nums[mid]) // 说明包含旋转区间
                {
                    end = mid - 1;
                }
                else if (nums[begin] == nums[mid]) // 说明target在num[mid+1]~num[end]区间内
                {
                    begin = mid + 1;
                }
            }
            else if (target > nums[mid])
            {
                if (nums[mid] < nums[end]) // 说明是递增区间
                {
                    if (target <= nums[end])
                    {
                        begin = mid + 1;
                    }
                    else if (target > nums[end])
                    {
                        end = mid - 1;
                    }
                }
                else if (nums[mid] > nums[end]) // 说明包含旋转数组
                {
                    begin = mid + 1;
                }
                else if (nums[mid] == nums[end]) // 说明target在num[begin]~num[mid-1]区间内
                {
                    return -1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
