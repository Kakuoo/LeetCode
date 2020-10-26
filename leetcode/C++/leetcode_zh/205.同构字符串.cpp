/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        // 构建s->t和t->s的哈希表
        unordered_map<char, int> record_1;
        unordered_map<char, int> record_2;
        for (int i = 0; i < s.size(); i++)
        {
            record_1[s[i]] = i;
            record_2[t[i]] = i;
        }

        // 遍历字符串，检查哈希表
        for (int i = 0; i < s.size(); i++)
        {
            if (record_1[s[i]] != record_2[t[i]])
            {
                return false;
            }
        }
        return true;
    }
};

// 参照290题的写法，其实可以不需要使用map<char,char>，使用map<char,int>更为方便
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        // 构建s->t和t->s的哈希表
        unordered_map<char, char> record_1;
        unordered_map<char, char> record_2;
        for (int i = 0; i < s.size(); i++)
        {
            record_1[s[i]] = t[i];
            record_2[t[i]] = s[i];
        }

        // 遍历字符串，检查哈希表
        for (int i = 0; i < s.size(); i++)
        {
            if (record_1[s[i]] != t[i] || record_2[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
