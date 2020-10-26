/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (k < 2)
            {
                nums[k++] = nums[i];
            }
            else if (k >= 2)
            {
                if (nums[k - 2] != nums[i])
                {
                    nums[k++] = nums[i];
                }
            }
        }
        return k;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        for (auto i = nums.begin() + 2; i != nums.end(); i++)
        {
            if (*i == *(i - 2))
            {
                nums.erase(i);
                i--;
            }
        }
        return nums.size();
    }
};

// @lc code=end
