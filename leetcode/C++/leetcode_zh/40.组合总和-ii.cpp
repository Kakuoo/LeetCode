/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.01%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    45.7K
 * Total Submissions: 75.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 无论是回溯法或是位运算法，整体时间复杂度都是O(2^n)，过多错误尝试，浪费时间
// 需在回溯过程中**剪枝**
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set; // 备份已插入集合，防止重复

        sort(candidates.begin(), candidates.end());
        generate(0, candidates, item, result, res_set, 0, target);
        return result;
    }

    void generate(int i, vector<int> &candidates,
                  vector<int> &item,
                  vector<vector<int>> &result,
                  set<vector<int>> &res_set,
                  int sum, int target)
    {
        if (i >= candidates.size() || sum > target) // 递归退出条件
            return;
        
        sum += candidates[i];
        
        item.push_back(candidates[i]);
        if (sum == target && res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }

        generate(i + 1, candidates, item, result, res_set, sum, target);
        sum -= candidates[i];
        item.pop_back();
        generate(i + 1, candidates, item, result, res_set, sum, target);
    }
};
// @lc code=end
