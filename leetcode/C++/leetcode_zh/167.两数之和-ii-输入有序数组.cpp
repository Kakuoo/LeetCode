/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// 双指针
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                return {left + 1, right + 1};
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
        }
        return {};
    }
};

// 二分搜索
// 有序数组中，搜索nums[i] 和 target - nums[i]
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         int left = 0;
//         int right = numbers.size() - 1;
//         while (left < right)
//         {
//             int mid = left + (right - left) >> 1;
//             if (numbers[mid] < (target - numbers[mid]))
//             {
//                 right = mid + 1;
//             }
//             else if (numbers[mid] == (target - numbers[mid]))
//             {
//                 int pos = find(numbers.begin(), numbers.end(), target - numbers[mid]) - numbers.begin();
//                 return {mid + 1, pos + 1};
//             }
//             else if (numbers[mid] > (target - numbers[mid]))
//             {
//                 left = mid + 1;
//             }
//         }
//         return {-1, -1};
//     }
// };


// Time Limit Exceeded
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         for (int i = 0; i < numbers.size(); i++)
//         {
//             int index = BinarySearch(numbers, i + 1, target - numbers[i]);
//             if (index != -1)
//             {
//                 return {i + 1, index + 1};
//             }
//         }
//         return {};
//     }

//     int BinarySearch(vector<int> &nums, int start, int target)
//     {
//         int left = start;
//         int right = nums.size() - 1;
//         while (left <= right)
//         {
//             int mid = left + (right - left) >> 1;
//             if (nums[mid] == target)
//                 return mid;
//             else if (nums[mid] < target)
//                 left = mid + 1;
//             else if (nums[mid] > target)
//                 right = mid - 1;
//         }
//         return -1;
//     }
// };


// Time Limit Exceeded
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         vector<int> res;
//         for (int i = 0; i < numbers.size() - 1; i++)
//         {
//             for (int j = i + 1; j < numbers.size(); j++)
//             {
//                 if (numbers[i] + numbers[j] == target)
//                 {

//                     res.push_back(i + 1);
//                     res.push_back(j + 1);
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
// @lc code=end
