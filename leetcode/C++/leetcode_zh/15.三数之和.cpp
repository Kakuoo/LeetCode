/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// 排序 + 双指针
// runtime 88 ms 80.6%
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (nums.size() - 2) && nums[i] <= 0; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            int target = 0 - nums[i];
            while (left < right /* && nums[right] >= 0 */) // 如果nums[k]<0，则三数之和肯定小于0（加上此步判断，反而更慢了）
            {
                if (nums[left] + nums[right] == target)
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else /* if (nums[left] + nums[right] > target) */
                {
                    right--;
                }
            }
        }

        return ret;
    }
};

// // 排序 + 三重循环 time limited
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         vector<vector<int>> ret;
//         if (nums.size() < 3)
//             return ret;
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++)
//         {
//             if (i != 0 && nums[i] == nums[i - 1])
//             {
//                 continue;
//             }
//             for (int j = i + 1; j < nums.size() - 1; j++)
//             {
//                 if (j != i + 1 && nums[j] == nums[j - 1])
//                 {
//                     continue;
//                 }
//                 for (int k = j + 1; k < nums.size(); k++)
//                 {
//                     if (k != j + 1 && nums[k] == nums[k - 1])
//                     {
//                         continue;
//                     }
//                     if (nums[i] + nums[j] + nums[k] == 0)
//                     {
//                         ret.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         return ret;
//     }
// };
// @lc code=end
