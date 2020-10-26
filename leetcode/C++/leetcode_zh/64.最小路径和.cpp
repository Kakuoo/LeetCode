/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (64.50%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    78.5K
 * Total Submissions: 120.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <limits.h>
using namespace std;

// 原地操作
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (i == grid.size() - 1 && j == grid[0].size() - 1)
                    continue;
                grid[i][j] += min((i == grid.size() - 1) ? INT_MAX : grid[i + 1][j], 
                                  (j == grid[0].size() - 1) ? INT_MAX : grid[i][j + 1]);
            }
        }
        return grid.front().front();
    }
};


class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        // 初始化二维dp数组，记录到达各点的路径最小总和
        vector<vector<int>> dp;
        for (int i = 0; i < grid.size(); i++)
        {
            dp.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++)
            {
                dp[i].push_back(0);
            }
        }

        int row = grid.size();
        int col = grid[0].size();
        dp[row - 1][col - 1] = grid[row - 1][col - 1];

        // 初始化dp数组最后一行
        for (int j = col - 2; j >= 0; j--)
        {
            dp[row - 1][j] = dp[row - 1][j + 1] + grid[row - 1][j];
        }

        // 初始化dp数组最后一列
        for (int i = row - 2; i >= 0; i--)
        {
            dp[i][col - 1] = dp[i + 1][col - 1] + grid[i][col - 1];
        }

        // DP推导
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = col - 2; j >= 0; j--)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }

        return dp[0][0];
    }
};

// 状态转移方程
// dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];

        int row = grid.size();
        int col = grid[0].size();
        
        for (int j = 1; j < col; ++j)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < row; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0]; // 可以将本循环和下个循环合并成一个循环
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};
// @lc code=end
