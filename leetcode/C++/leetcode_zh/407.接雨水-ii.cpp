/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 *
 * https://leetcode-cn.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (34.37%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 7.9K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * 给你一个 m x n 的矩阵，其中的值均为正整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
 * 
 * 
 * 
 * 示例：
 * 
 * 给出如下 3x6 的高度图:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 * 
 * 返回 4 。
 * 
 * 
 * 
 * 
 * 如上图所示，这是下雨前的高度图[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] 的状态。
 * 
 * 
 * 
 * 
 * 
 * 下雨后，雨水将会被存储在这些方块中。总的接雨水量是4。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 110
 * 0 <= heightMap[i][j] <= 20000
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

/*
 * 思考：
 * 积水的多少和四个边界（上下左右）上与底面相连的最低点的高度相关
 * 
 * 想象水流从外往里流，慢慢上升
 */

/*
 * 广度优先搜索
 * 1.搜索队列使用优先级队列（堆），越低的点优先级越高（最小堆），越优先搜索。
 * 2.以矩形四周的点作为起始点进行广度优先搜索（这些点最初push进入队列）
 * 3.使用一个二维数组对push进入队列的点进行标记，之后搜索到该点后，不再push到队列中。
 * 4.只要优先级队列不空，即取出优先级队列头元素进行搜索，按照上下左右四个方向进行拓展，
 * 拓展过程中忽略超出边界与已入队列的点。
 * 5.当对某点(x, y, h)进行拓展时（h为heightMap[x][y]）：得到的新点(newx, newy)，高度为heightMap[newx][newy]，
 * 如果h大于heightMap[newx][newy]：
 *      最终结果 += h - heightMap[newx][newy];
 *      将heightMap[newx][newy]复制为h（即升高该位置的水平面）
 * 将(newx, newy, heightMap[newx][newy])push进入优先级度列，并做标记
 * 
 */

struct Qitem
{
    int x, y, h;
    Qitem(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
};

struct cmp
{
    bool operator()(const Qitem &a, const Qitem &b)
    {
        return a.h > b.h; // 最小堆
    }
};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        priority_queue<Qitem, vector<Qitem>, cmp> Q;
        if (heightMap.size() < 3 || heightMap[0].size() < 3)
            {
                return 0; // 行数或列数小于3，则必然无法积水
            }
        int row = heightMap.size();
        int col = heightMap[0].size();
        vector<vector<int>> mark;
        for (int i = 0; i < row; i++)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < col; j++)
            {
                mark[i].push_back(0);
            }
        }
        // for (auto i : row)
        // {
        //     mark.push_back(vector<int>());
        //     for (auto j : col)
        //     {
        //         mark[i].push_back(0);
        //     }
        // }

        // 构造最小堆，取矩形最外侧的左右两边
        for (int i = 0; i < row; i++)
        {
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, col - 1, heightMap[i][col - 1]));
            mark[i][col - 1] = 1;
        }
        // 构造最小堆，取矩形最外侧的上下两边
        for (int j = 1; j < col - 1; j++)
        {
            Q.push(Qitem(0, j, heightMap[0][j]));
            mark[0][j] = 1;
            Q.push(Qitem(row - 1, j, heightMap[row - 1][j]));
            mark[row - 1][j] = 1;
        }

        // 开始搜索，搜索顺序 上->下->左->右
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        int result = 0;
        while (!Q.empty())
        {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x < 0 || new_x >= row ||
                    new_y < 0 || new_y >= col ||
                    mark[new_x][new_y]) // 若已加入队列
                {
                    continue;
                }
                // 若当前点高度高于拓展点时
                if (h > heightMap[new_x][new_y])
                {
                    result += h - heightMap[new_x][new_y];
                    heightMap[new_x][new_y] = h;
                }
                Q.push(Qitem(new_x, new_y, heightMap[new_x][new_y]));
                mark[new_x][new_y] = 1;
            }
        }
        return result;
    }
};
// @lc code=end
