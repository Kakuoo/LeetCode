/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (63.62%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 81.7K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.empty())
            return 0;

        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); i++)
        {
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i].push_back(0);
            }
        }

        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++)
            dp[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];

        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = triangle[i].size() - 1; j >= 0; j--)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};

// 原位操作
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

/*
 * 从下往上分析可知
 * dp[i][j]可由dp[i+1][j], dp[i+1][j+1]到达
 * 利用i循环，从倒数第二层递推至第一层，对于每层的各列，进行动态规划递推：
 * 第i行第j列的最优解为dp[i][j]，可到达(i, j)位置的两个最优解为dp[i+1][j], dp[i+1][j+1]
 * 状态转移方程为dp[i][j]=min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
 * 最后返回dp[0][0]
 * 
 */

// Dynamic programming
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0)
            return 0;

        // 初始化二维dp数组
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); ++i)
        {
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                dp[i].push_back(0);
            }
        }

        // 初始化dp数组的最后一行
        for (int j = 0; j < dp[dp.size() - 1].size(); ++j)
        {
            dp[dp.size() - 1][j] = triangle[triangle.size() - 1][j];
        }

        // DP
        for (int i = dp.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
