/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.empty())
            return "";

        string res;
        int right = s.size() - 1;
        while (0 <= right)
        {
            //从后往前寻找第一字符
            while (0 <= right && s[right] == ' ')
                right--;
            if (right < 0) // 处理测试样例 "  hello world!  "
                break;

            //从后往前寻找第一个空格
            int word_left = right;
            while (word_left >= 0 && s[word_left] != ' ')
                word_left--;

            res += s.substr(word_left + 1, right - word_left);
            res += ' ';

            right = word_left;
        }

        //去除最后一个字符空格
        if (!res.empty())
            res.pop_back();

        return res;
    }
};

// // stack + istringstream
// // 8ms runtime: 99.7 %, memory 31%
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         stack<string> S;
//         string res, tmp;
//         istringstream is(s);

//         while (is >> tmp)
//             S.push(tmp);

//         if (S.empty())
//             return "";

//         while (!S.empty())
//         {
//             res += S.top() + " ";
//             S.pop();
//         }

//         res.pop_back();

//         return res;
//     }
// };
// @lc code=end
