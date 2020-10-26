/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                swap(nums[k++], nums[i]);
        }
    }
};

// class Solution
// {
// public:
//     void moveZeroes(vector<int> &nums)
//     {
//         int k = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] != 0)
//                 nums[k++] = nums[i];
//         }

//         for (int i = k; i < nums.size(); i++)
//         {
//             nums[i] = 0;
//         }
//     } 
// };
// @lc code=end
