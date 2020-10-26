/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (58.87%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    25.5K
 * Total Submissions: 43.1K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;   // 去重
        sort(nums.begin(), nums.end());
        // res_set.insert(item);
        result.push_back(item);
        generate(0, nums, item, result, res_set);
        return result;
    }

private:
    void generate(int i, vector<int> &nums,
                  vector<int> &item,
                  vector<vector<int>> &result,
                  set<vector<int>> &res_set)
    {
        if (i >= nums.size())
        {
            return;
        }
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end())    // 如果res_set中无法找到item，说明此item不重复
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, item, result, res_set);
        item.pop_back();
        generate(i + 1, nums, item, result, res_set);
    }
};
// @lc code=end
