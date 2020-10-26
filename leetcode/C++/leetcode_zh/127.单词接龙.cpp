/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (39.54%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 77K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

/* 
 * 图的宽度优先搜索
 * 寻找最短边
 * 
 * 使用map构建邻接表 表示的图，map定义为以string为key（代表图的顶点），
 * vector<string>为value（代表图的各个顶点邻接的顶点）
 */

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> graph;
        ConstructGraph(beginWord, wordList, graph);
        return BFS(beginWord, endWord, graph);
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
        // 添加起始节点
        word_list.push_back(begin_word);
        for (int i = 0; i < word_list.size(); i++)
        {
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
        }
    }

    int BFS(const string &begin_word, const string &end_word,
            map<string, vector<string>> &graph)
    {
        set<string> visit;
        queue<pair<string, int>> Q;
        Q.push(make_pair(begin_word, 1));
        visit.insert(begin_word);
        while (!Q.empty())
        {
            string cur_str = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (cur_str == end_word)
            {
                return step;
            }
            const vector<string> &neighbors = graph[cur_str];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if (visit.find(neighbors[i]) == visit.end())
                {
                    Q.push(make_pair(neighbors[i], step + 1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return 0;
    }
};

// @lc code=end
