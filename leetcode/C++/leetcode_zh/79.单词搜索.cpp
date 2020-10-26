/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.38%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 127.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

// 44ms, runtime 54.78%
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || word.empty())
            return false;

        row = board.size();
        col = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                bool flag = SearchWord(board, word, 0, i, j);

                if (flag)
                    return true;
            }
        }

        return false;
    }

private:
    const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};     // 搜索顺序 上右下左
    int row, col; // 二维平面的行，列
    vector<vector<bool>> visited;

    bool IsInArea(int x, int y)
    {
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    bool SearchWord(const vector<vector<char>> &board, const string &word, 
                    int index, int start_x, int start_y)
    {
        if (index == word.size() - 1)
            return board[start_x][start_y] == word[index];
        
        if (board[start_x][start_y] == word[index])
        {
            visited[start_x][start_y] = true;

            for (int i = 0; i < 4; i++)
            {
                int new_x = start_x + d[i][0];
                int new_y = start_y + d[i][1];
                
                if (IsInArea(new_x, new_y) && visited[new_x][new_y] == false)
                {
                    bool flag = SearchWord(board, word, index + 1, new_x, new_y);

                    if (flag)
                        return true;
                }
            }
            visited[start_x][start_y] = false;
        }

        return false;
    }
};


class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // ios::sync_with_stdio(false);
        if (board.empty() || word.empty())
            return false;
        int row = board.size(), col = board[0].size();
        vector<vector<int>> mark(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (dfs(board, word, 0, i, j, mark))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string &word,
             int word_idx, int x, int y, vector<vector<int>> &mark)
    {
        if (word_idx == word.size())
            return true;
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size() ||
            board[x][y] != word[word_idx])
        {
            return false;
        }

        ///////////////////////////////////////////////////////////
        // 此两种方法任选一种 （1）
        ///////////////////////////////////////////////////////////
        if (mark[x][y] == 0)
        {
            mark[x][y] = 1;
            static const int dx[] = {-1, 1, 0, 0};
            static const int dy[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; ++i)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (dfs(board, word, word_idx + 1, new_x, new_y, mark))
                    return true;
            }
            /**
             * 下面一行代码对于此种测试样例非常重要
             * [["C","A","A"],["A","A","A"],["B","C","D"]]
             * "AAB"
             */
            mark[x][y] = 0;
        }
        return false;

        ///////////////////////////////////////////////////////////
        // 此两种方法任选一种 （2）
        ///////////////////////////////////////////////////////////
        if (mark[x][y] == 0)
        {
            mark[x][y] = 1;
            if (dfs(board, word, word_idx + 1, x + 1, y, mark) || dfs(board, word, word_idx + 1, x - 1, y, mark) || dfs(board, word, word_idx + 1, x, y + 1, mark) || dfs(board, word, word_idx + 1, x, y - 1, mark))
                return true;
            /**
             * 下面一行代码对于此种测试样例非常重要
             * [["C","A","A"],["A","A","A"],["B","C","D"]]
             * "AAB"
             */
            mark[x][y] = 0;
        }
        return false;
        ///////////////////////////////////////////////////////////
    }
};

// @lc code=end
