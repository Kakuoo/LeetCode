/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        if (nums.empty())
            return res;

        vector<int> p;
        used = vector<bool>(nums.size(), false);
        GeneratePermutation(nums, 0, p);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

private:
    // p中保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index + 1个元素，获得一个由index + 1个元素的排列
    void GeneratePermutation(vector<int> &nums, int index, vector<int> &p)
    {
        if (index == nums.size())
        {
            // 保存当前排列
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 判断当前nums[i]是否在p的结果中，如果不在的话，再执行下式
            if (used[i] == false)
            {
                p.push_back(nums[i]);
                used[i] = true;
                GeneratePermutation(nums, index + 1, p);

                // 恢复状态量
                p.pop_back();
                used[i] = false; 
            }
        }
        return;
    }
};
// @lc code=end
