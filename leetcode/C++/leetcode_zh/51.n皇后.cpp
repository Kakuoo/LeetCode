/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (67.99%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 44.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> checkboard; // 标记棋盘是否可以放置皇后的二维数组
        vector<string> location;        // 存储某个拜访结果，当完成一次递归找到结果后，将location push进入result
        vector<vector<string>> result;  // 最终存储结果的数组
        for (int i = 0; i < n; i++)
        {
            checkboard.push_back(vector<int>()); //
            for (int j = 0; j < n; j++)
            {
                checkboard[i].push_back(0); // 将二维棋盘填充0
            }
            location.push_back("");
            location[i].append(n, '.'); // 将二维棋盘填充'.'
        }
        generate(0, n, location, result, checkboard);
        return result;
    }

private:
    void generate(int k, int n, vector<string> &location,    // 正在放置第k个皇后
                  vector<vector<string>> &result, vector<vector<int>> &checkboard)
    {
        if (k >= n)
        {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; i++) // 顺序处理o~n-1列
        {
            if (checkboard[k][i] == 0)
            {
                vector<vector<int>> tmp_checkboard = checkboard; // 记录回溯前皇后的位置
                location[k][i] = 'Q';                            // 记录当前皇后的位置
                put_down_the_queen(k, i, checkboard);
                generate(k + 1, n, location, result, checkboard);
                checkboard = tmp_checkboard;
                location[k][i] = '.'; // 将当前尝试的皇后位置重置为 '.'
            }
        }
    }

    void put_down_the_queen(int x, int y,
                            vector<vector<int>> &checkboard)
    {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // 方向数组
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        checkboard[x][y] = 1;                       // 放置皇后
        for (int i = 1; i < checkboard.size(); i++) // 遍历棋盘的行列数
        // i = 1是因为方向数组dx，dy中有-1值
        {
            for (int j = 0; j < 8; j++) // 遍历皇后周边的8个方向
            {
                int new_x = x + i * dx[j]; // 新的位置向8个方向延伸，每个位置最多延伸 N-1
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < checkboard.size() && new_y >= 0 && new_y < checkboard.size()) // 检查新位置是否还在棋盘中
                {
                    checkboard[new_x][new_y] = 1;
                }
            }
        }
    }
};
// @lc code=end
