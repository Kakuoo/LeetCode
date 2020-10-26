/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.90%)
 * Likes:    466
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 160.4K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

/*
 * 方法一：深度优先搜索（DFS）
 * 方法二：宽度优先搜索（BFS）
 * 
 */

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int island_num = 0;
        vector<vector<int>> mark;
        // vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size(), 0));   // 错误！！！并没有说明岛屿一定是正方形的

        for (int i = 0; i < grid.size(); i++)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++)
            {
                mark[i].push_back(0);
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (mark[i][j] == 0 && grid[i][j] == '1')
                {
                    DFS(mark, grid, i, j);
                    // BFS(mark, grid, i, j);
                    island_num++;
                }
            }
        }
        return island_num;
    }

private:
    void DFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid, int x, int y)
    {
        mark[x][y] = 1; // 标记已搜索的位置
        // 设置方向数组，搜索顺序-->上下左右
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i]; // vector中x为行
            int new_y = y + dy[i]; // vector中y为列
            if (new_x < 0 || new_x >= mark.size() ||
                new_y < 0 || new_y >= mark[new_x].size())
            {
                continue;
            }
            // 如果当前位置为陆地且未搜索过
            if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
            {
                DFS(mark, grid, new_x, new_y);
            }
        }
    }

    void BFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid, int x, int y)
    {
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));
        mark[x][y] = 1;
        while (!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop(); // 弹出队头元素
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x < 0 || new_x >= mark.size() ||
                    new_y < 0 || new_y >= mark[new_x].size())
                {
                    continue;
                }
                if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
                {
                    Q.push(make_pair(new_x, new_y)); // 将新位置push入队伍等待搜索
                    mark[new_x][new_y] = 1;          // 并做标记
                }
            }
        }
    }
};

// @lc code=end
