/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (31.28%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 27.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: []
 * 
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct Qitem
{
    string node;    // 搜索节点
    int parent_pos; // 前驱节点在队列中的位置
    int step;       // 到达当前节点的步数
    Qitem(string node, int parent_pos, int step) : node(node), parent_pos(parent_pos), step(step) {}
};

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> graph;
        ConstructGraph(beginWord, wordList, graph);
        vector<Qitem> Q;          // 使用vector实现队列
        vector<int> end_word_pos; // end_word在搜索队列中的位置
        vector<vector<string>> result;
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);
        for (int i = 0; i < end_word_pos.size(); i++)
        {
            int pos = end_word_pos[i];
            vector<string> path;
            while (pos != -1) // 从end_word到begin_word将路径上的节点值push进入path
            {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(vector<string>());
            for (int j = path.size() - 1; j >= 0; j--)
            {
                result[i].push_back(path[j]);
            }
        }
        return result;
    }

private:
    bool connect_bool(const string &word1, const string &word2)
    {
        int cnt = 0; // 记录不同字符的数量
        for (int i = 0; i < word1.size(); i++)
        {
            if (word1[i] != word2[i])
            {
                cnt++;
            }
        }
        return cnt == 1;
    }

    void ConstructGraph(const string &begin_word,
                        vector<string> &word_list,
                        map<string, vector<string>> &graph)
    {
        int has_begin_word_flag = 0;
        for (int i = 0; i < word_list.size(); i++)
        {
            if (word_list[i] == begin_word)
            {
                has_begin_word_flag = 1; // 由于word_list中可能含有begin_word，直接将begin_word push进入wordlist，会出现重复结果
            }
            graph[word_list[i]] = vector<string>();
        }
        for (int i = 0; i < word_list.size(); i++)
        {
            for (int j = i + 1; j < word_list.size(); j++)
            {
                if (connect_bool(word_list[i], word_list[j]))
                {
                    graph[word_list[i]].push_back(word_list[j]);
                    graph[word_list[j]].push_back(word_list[i]);
                }
            }
            if (has_begin_word_flag == 0 && connect_bool(begin_word, word_list[i]))
            {
                graph[begin_word].push_back(word_list[i]);
            }
        }
    }

    void BFS_graph(const string &begin_word, const string &end_word,
                   map<string, vector<string>> &graph,
                   vector<Qitem> &Q, vector<int> &end_word_pos)
    {
        map<string, int> visit; // <单词， 步数>
        int min_step = 0;       // 到达end_word的最小步数
        int front = 0;          // 队列头指针，指向vector表示的队列头
        Q.push_back(Qitem(begin_word, -1, 1));
        visit[begin_word] = 1;
        while (front != Q.size()) // front指向Q.size()即vector尾部时，队列为空 !Q[front].node.empty()
        {
            const string &node = Q[front].node;
            int step = Q[front].step;
            if (min_step != 0 && step > min_step) // 代表所有到终点的路径都已搜索完成
            {
                break;
            }
            if (node == end_word)
            {
                min_step = step; // 当搜索到结果时，记录到达终点的最小步数
                end_word_pos.push_back(front);
            }
            // 宽度优先搜索常规操作，遍历邻接表
            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if (visit.find(neighbors[i]) == visit.end() ||
                    visit[neighbors[i]] == step + 1)
                {
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
    }
};
// @lc code=end
