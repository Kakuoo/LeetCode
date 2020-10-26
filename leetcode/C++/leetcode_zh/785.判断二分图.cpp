/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 *
 * https://leetcode-cn.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (42.60%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 14.5K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * 给定一个无向图graph，当这个图为二分图时返回true。
 * 
 * 如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
 * 
 * 
 * graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边：
 * graph[i] 中不存在i，并且graph[i]中没有重复的值。
 * 
 * 
 * 
 * 示例 1:
 * 输入: [[1,3], [0,2], [1,3], [0,2]]
 * 输出: true
 * 解释: 
 * 无向图如下:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * 我们可以将节点分成两组: {0, 2} 和 {1, 3}。
 * 
 * 
 * 
 * 
 * 示例 2:
 * 输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * 输出: false
 * 解释: 
 * 无向图如下:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * 我们不能将节点分割成两个独立的子集。
 * 
 * 
 * 注意:
 * 
 * 
 * graph 的长度范围为 [1, 100]。
 * graph[i] 中的元素的范围为 [0, graph.length - 1]。
 * graph[i] 不会包含 i 或者有重复的值。
 * 图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 深度优先搜索
// 0:未访问  1:深色  -1:浅色
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        // 对每个点染色 一旦在染的过程中发现有相连的两个顶点已经被染成相同的颜色，说明不是二分图
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i)
        {
            // 如果没被染色 并且返回false 说明不是
            if (colors[i] == 0 && !dfs(graph, 1, i, colors))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph,
             int color, int curr, vector<int> &colors)
    {
        // 如果这个节点已经上过色了 如果该颜色和将要染的颜色相同 就返回true
        if (colors[curr] != 0)
            return colors[curr] == color;
        // 如果没被染色，则将当前顶点染色，
        colors[curr] = color;
        // 然后再遍历与该顶点的邻接点 递归 如果返回false 就返回false
        for (auto i : graph[curr])
        {
            // 相邻的点染成不同的颜色 1 和 -1
            if (!dfs(graph, -1 * color, i, colors))
            {
                return false;
            }
        }
        return true;
    }
};

// 广度优先搜索
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        queue<int> Q;
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i)
        {
            if (colors[i] != 0)
                continue;
            if (colors[i] == 0 && !bfs(graph, i, Q, colors))
                return false;
        }
        return true;
    }

    bool bfs(vector<vector<int>> &graph,
             int curr, queue<int> &Q, vector<int> &colors)
    {
        colors[curr] = 1;
        Q.push(curr);
        while (!Q.empty())
        {
            int tmp = Q.front();
            Q.pop();
            for (auto e : graph[tmp])
            {
                if (colors[e] == colors[tmp])
                    return false;
                if (colors[e] == 0)
                {
                    colors[e] = -1 * colors[tmp];
                    Q.push(e);
                }
            }
        }
        return true;
    }
};

// @lc code=end
