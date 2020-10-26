/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if (digits == "")
            return res;

        FindCombination(digits, 0, "");
        return res;
    }

private:
    // s中保存了此时从digits[0...index - 1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字母，得到digits[0...index]翻译得到的解
    void FindCombination(const string &digits, int index, const string s)
    {
        if (index == digits.size())
        {
            // s为一个解，保存s
            res.push_back(s);
            return;
        }

        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');

        string letters = letter_map[c - '0'];
        for (int i = 0; i < letters.size(); i++)
        {
            FindCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }

private:
    vector<string> res;
    const string letter_map[10] =
        {
            " ",    // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
    };
};

// @lc code=end
