/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.23%)
 * Likes:    783
 * Dislikes: 0
 * Total Accepted:    81.3K
 * Total Submissions: 110.6K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate("", n, 0, 0, result);
        return result;
    }

    void generate(string item, int n, int left, int right, vector<string> &result)
    {
        if (left == n && right == n)
        {
            result.push_back(item);
            return;
        }
        
        if (left < n)
        {
            generate(item + '(', n, left + 1, right, result);
        }
        if (right < left)
        {
            generate(item + ')', n, left, right + 1, result);
        }
    }
};
// @lc code=end
