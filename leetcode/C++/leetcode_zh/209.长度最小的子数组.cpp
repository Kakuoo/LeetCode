/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

// 滑动窗口
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        // nums[l...r] 为滑动窗口的范围
        int l = 0;
        int r = -1;
        int sum = 0;
        int len = INT_MAX;

        while (l < nums.size())
        {
            if (sum < s && r + 1 < nums.size())
            {
                r++;
                sum += nums[r];
            }
            else
            {
                sum -= nums[l];
                l++;
            }

            if (sum >= s)
            {
                len = min(len, r - l + 1);
            }
        }

        if (len == INT_MAX)
            return 0;

        return len;
    }
};

// 暴力解法 Time Limit Exceeded
// class Solution
// {
// public:
//     int minSubArrayLen(int s, vector<int> &nums)
//     {
//         int len = INT_MAX;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i; j < nums.size(); j++)
//             {
//                 for (int k = i; k <= j; k++)
//                 {
//                     sum += nums[k];
//                 }
//                 if (sum >= s)
//                 {
//                     len = min(len, j - i + 1);
//                 }
//                 sum = 0;
//             }
//         }

//         if (len == INT_MAX) // 无解时
//             return 0;
//         return len;
//     }
// };
// @lc code=end
