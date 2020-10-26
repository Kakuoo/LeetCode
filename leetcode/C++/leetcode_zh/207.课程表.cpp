/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (49.17%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    29.7K
 * Total Submissions: 59.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

// struct GraphNode
// {
//     int label;
//     vector<GraphNode *> neighbors;
//     GraphNode(int x) : label(x) {}
// };

class Solution
{
    enum
    {
        TODO,
        DOING,
        DONE
    };

public:
    // 方法一 深度优先搜索
    // sol1 dfs based topo
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(n);  // 图的邻接表
        for (auto &&e : prerequisites) // prerequisites 结构 <高级课程int, 低级课程int>
        {
            graph[e[1]].emplace_back(e[0]);
        }
        vector<int> visit(n, TODO); // visit访问矩阵，用于记录访问信息
        for (int i = 0; i < n; ++i)
        {
            if (has_cycle(i, visit, graph))
                return false;
        }
        return true;
    }
    bool has_cycle(int current, vector<int> &visit, vector<vector<int>> &graph)
    {
        if (visit[current] == DOING)
            return true;
        if (visit[current] == DONE)
            return false;
        visit[current] = DOING;
        for (auto &&v : graph[current])
        {
            if (has_cycle(v, visit, graph))
                return true;
        }
        visit[current] = DONE;
        return false;
    }

    // 方法二 广度优先搜索
    // sol2 bfs based topological sort
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(n); // 图的邻接表
        vector<int> indegree(n);      // 入度数组
        for (auto &&e : prerequisites)
        {
            graph[e[1]].emplace_back(e[0]);
            ++indegree[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!indegree[i])
                q.emplace(i);
        }
        vector<int> seq;
        while (q.size())
        {
            int current = q.front();
            q.pop();
            seq.emplace_back(current);
            for (int v : graph[current])
            {
                if (--indegree[v] == 0)
                    q.emplace(v);
            }
        }
        return seq.size() == n;
    }
};

// DFS求解
// class Solution
// {
// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         vector<vector<int>> graph(numCourses, vector<int>(0));
//         for (auto prq : prerequisites)
//         {
//             graph[prq[1]].push_back(prq[0]);
//         }
//         vector<int> visited(numCourses, 0);
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (!judge(graph, visited, i))
//                 return false;
//         }
//         return true;
//     }
//     bool judge(vector<vector<int>> &graph, vector<int> &visited, int i)
//     {
//         if (visited[i] == -1)
//             return false;
//         if (visited[i] == 1)
//             return true;
//         visited[i] = -1;
//         for (auto itm : graph[i])
//         {
//             if (!judge(graph, visited, itm))
//                 return false;
//         }
//         visited[i] = 1;
//         return true;
//     }
// };

// 方法一
// 深度优先搜索 （基于不同的接口） vector<pair<int, int>> &prerequisites
// class Solution
// {
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
//     {
//         vector<GraphNode *> graph;
//         vector<int> visit;
//         for (int i = 0; i < numCourses; i++)
//         {
//             graph.push_back(new GraphNode(i));
//             visit.push_back(-1);
//         }
//         for (int i = 0; i < prerequisites.size(); i++)
//         {
//             GraphNode *begin = graph[prerequisites[i].second];
//             GraphNode *end = graph[prerequisites[i].first];
//             begin->neighbors.push_back(end);
//         }
//         for (int i = 0; i < graph.size(); i++)
//         {
//             if (visit[i] == -1 && !DFS_graph(graph[i], visit)) // 如果节点没访问过，则进行DFS，如果DFS遇到环，返回无法完成
//             {
//                 return false;
//             }
//         }
//         for (int i = 0; i < numCourses; i++)
//         {
//             delete graph[i];
//         }
//         return true;
//     }

// private:
//     // 节点访问状态：-1，没有访问过，0，正在访问，1，已完成访问
//     bool DFS_graph(GraphNode *node, vector<int> &visit)
//     {
//         visit[node->label] = 0;
//         for (int i = 0; i < node->neighbors.size(); i++)
//         {
//             if (visit[node->neighbors[i]->label] == -1)
//             {
//                 if (DFS_graph(node->neighbors[i], visit) == 0)
//                 {
//                     return false;   // 节点已被访问过，或者有环
//                 }
//             }
//             else if (visit[node->neighbors[i]->label] == 0)
//             {
//                 return false;   // 有环
//             }
//         }
//         visit[node->label] = 1;
//         return true;
//     }
// };

// 方法二
// 广度优先搜索 （基于不同的接口） vector<pair<int, int>> &prerequisites
// 利用 入度，一个节点的入度代表该节点依赖于几个邻接节点，当遍历完所有节点时，将全体节点的入度-1，所有节点的入度都为0则说明无环，
// class Solution
// {
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
//     {
//         vector<int> degree; // 入度数组
//         vector<GraphNode *> graph;
//         for (int i = 0; i < numCourses; i++)
//         {
//             degree.push_back(0);
//             graph.push_back(new GraphNode(i));
//         }
//         for (int i = 0; i < prerequisites.size(); i++)
//         {
//             GraphNode *begin = graph[prerequisites[i].second];
//             GraphNode *end = graph[prerequisites[i].first];
//             begin->neighbors.push_back(end);  // 入度++，即pari<课程1, 课程2>
//             degree[prerequisites[i].first]++; // 课程1的入度
//         }
//         queue<GraphNode *> Q;
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (degree[i] == 0)
//             {
//                 Q.push(graph[i]);
//             }
//         }
//         while (!Q.empty())
//         {
//             GraphNode *node = Q.front();
//             Q.pop();
//             for (int i = 0; i < node->neighbors.size(); i++)
//             {
//                 degree[node->neighbors[i]->label]--;
//                 if (degree[node->neighbors[i]->label] == 0)
//                 {
//                     Q.push(node->neighbors[i]);
//                 }
//             }
//         }
//         for (int i = 0; i < numCourses; i++)
//         {
//             delete graph[i];
//         }
//         for (int i = 0; i < degree.size(); i++)
//         {
//             if (degree[i])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// @lc code=end
