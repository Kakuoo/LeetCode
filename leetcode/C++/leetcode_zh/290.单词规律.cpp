/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (41.77%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 48.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// 分割字符串1
void divide_string1(string str)
{
    vector<string> word_vec;
    string tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            tmp += str[i];
        }
        else
        {
            word_vec.push_back(tmp);
            tmp = "";
        }
    }

    if (tmp.size() != 0)
        word_vec.push_back(tmp);
}

// 分割字符串2
void divide_string2(string str)
{
    vector<string> word_vec;
    istringstream is(str);
    string tmp;
    while (is >> tmp)
    {
        word_vec.push_back(tmp);
    }
}

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        // 提取str中以空格为分割符的单词
        string tmp_word;
        istringstream instr(str);
        vector<string> word_vec;
        while (instr >> tmp_word)
        {
            word_vec.push_back(tmp_word);
        }

        if (word_vec.size() != pattern.size())
            return false;

        // 构建pattern->str和str->pattern的哈希表
        unordered_map<char, string> record_1;
        unordered_map<string, char> record_2;
        for (int i = 0; i < word_vec.size(); i++)
        {
            record_1[pattern[i]] = word_vec[i];
            record_2[word_vec[i]] = pattern[i];
        }

        // 遍历哈希表，检查是否准确
        for (int i = 0; i < word_vec.size(); i++)
        {
            if (record_1[pattern[i]] != word_vec[i] || record_2[word_vec[i]] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool wordPattern(string pattern, string str)
//     {
//         map<string, char> word_map; // 单词到pattern字符的映射
//         char used_word[128] = {0};  // 已被映射的pattern字符
//         string temp_word;           // 临时保存拆分出的单词
//         int pos = 0;                // 当前指向的pattern字符
//         str.push_back(' ');         // str尾部加入一个空格，使遇到空格分割单词（无需特殊处理最后一个单词）
//         for (int i = 0; i < str.length(); i++)
//         {
//             if (str[i] == ' ') // 遇到空格,拆分一个新单词
//             {
//                 if (pos == pattern.length())
//                 {
//                     return false; // 若分割出一个单词，但已无pattern字符与之对应
//                 }
//                 // 若单词未出现在hash映射中
//                 if (word_map.find(temp_word) == word_map.end())
//                 {
//                     if (used_word[pattern[pos]])
//                     {
//                         return false; // 如果当前pattern字符已使用
//                     }
//                     word_map[temp_word] = pattern[pos];
//                     used_word[pattern[pos]] = 1;
//                 }
//                 else
//                 {
//                     if (word_map[temp_word] != pattern[pos])
//                     {
//                         return false; // 若当前word已建立映射， 但是无法与当前pattern对应
//                     }
//                 }
//                 temp_word = "";
//                 pos++;
//             }
//             else
//             {
//                 temp_word += str[i];
//             }
//         }
//         if (pos != pattern.length())
//         {
//             return false; // 有多余的pattern字符
//         }
//         return true;
//     }
// };
// @lc code=end
