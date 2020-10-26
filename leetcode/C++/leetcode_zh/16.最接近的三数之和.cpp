/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() < 3)
            return NULL;

        sort(nums.begin(), nums.end());

        int ret = INT_MAX;
        int dist = INT_MAX;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int tmp_target = nums[i] + nums[left] + nums[right];
                if (abs(tmp_target - target) < dist)
                {
                    ret = tmp_target;
                    dist = abs(tmp_target - target);
                }

                if (tmp_target == target)
                {
                    return tmp_target;
                }
                else if (tmp_target < target)
                {
                    left++;
                }
                else // tmp_target > target
                {
                    right--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
