/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (58.32%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    93.3K
 * Total Submissions: 156.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

// 偷懒方法
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t ? true : false;
    }
};

// 比较合适的解法
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> vec(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }
        for (auto i : vec)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 使用哈希表
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i)
        {
            ++map[s[i]];
            --map[t[i]];
        }
        // unordered_map<char, int>::iterator it = map.begin();
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 自己写的方法，稍微繁琐
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        if (s.size() == 1 && t.size() == 1 && s != t)
        {
            return false;
        }
        vector<int> vec_s(26, 0);
        vector<int> vec_t(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            vec_s[s[i] - 'a']++;
            vec_t[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (vec_s[i] != vec_t[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
