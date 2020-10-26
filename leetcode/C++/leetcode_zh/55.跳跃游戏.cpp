/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return true;

        int maxDis = nums[0];

        for (int i = 1; i < len - 1; i++)
        {
            if (i <= maxDis)
            {
                maxDis = max(maxDis, nums[i] + i);
            }
        }

        return maxDis >= len - 1;
    }
};

class Solution
{
public:
    // bool canJump(vector<int> &nums)
    // {
    //     vector<int> index;
    //     // 计算index vector数组
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         index.push_back(i + nums[i]);
    //     }
    //     int jump_index = 0;
    //     int max_step = index[0];
    //     while (jump_index < index.size() && jump_index <= max_step)
    //     {
    //         if (max_step < index[jump_index])
    //         {
    //             max_step = index[jump_index];
    //         }
    //         jump_index++;
    //     }
    //     if (jump_index == index.size())
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (farthest <= i)
                return false;
        }
        return farthest >= nums.size() - 1;
    }
};
// @lc code=end
