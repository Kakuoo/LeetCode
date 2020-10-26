/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <cassert>
using namespace std;

// runtime 16 ms 79.85%
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int h = min(height[left], height[right]);
            res = max(res, h * (right - left));

            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};

// Time Limit Exceeded
// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int res = 0;
//         for (int i = 0; i < height.size() - 1; i++)
//         {
//             for (int j = i + 1; j < height.size(); j++)
//             {
//                 int h = min(height[i], height[j]);
//                 res = max(res, h * (j - i));
//             }
//         }
//         return res;
//     }
// };
// @lc code=end
