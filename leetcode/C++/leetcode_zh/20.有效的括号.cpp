/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.81%)
 * Likes:    1536
 * Dislikes: 0
 * Total Accepted:    260.9K
 * Total Submissions: 629.8K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                stack.push(')');
                break;
            case '[':
                stack.push(']');
                break;
            case '{':
                stack.push('}');
                break;
            default:                                          // 如果是其他三种情况 ')', ']', '}'
                if (stack.size() == 0 || s[i] != stack.top()) // 该条件不可颠倒
                    return false;
                stack.pop();
            }
        }
        return stack.size() == 0 ? true : false;
    }
};

// python写法
// class Solution:
//     def isValid(self, s):
//         while '{}' in s or '()' in s or '[]' in s:
//             s = s.replace('{}', '')
//             s = s.replace('[]', '')
//             s = s.replace('()', '')
//         return s == ''

// @lc code=end
