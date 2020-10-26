/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.68%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    63.6K
 * Total Submissions: 103.8K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

/*
 * 
 * 思考如何设计哈希表的key和value，能将各个字符数相同的字符串映射一起
 * 
 * 哈希表以内部进行排序的各个单词为key，以字符串向量(vecto<string>)为value，
 * 存储各个字符数量相同的字符串（anagram）
 * 
 */

/* 
 * 方法一：
 * 
 * 设置字符串到字符串向量的哈希表anagram，遍历字符串向量的strs中的strs[i]
 * 1）设置临时变量str=strs[i]，对str进行排序
 * 2）若str未出现在anagram中，设置str到一个空字符串向量的映射。
 * 3）将strs[i]添加至字符串向量anagram[str]中
 * 遍历哈希表anagram，将全部key对应的value，push到最终结果中
 * 
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 内部进行排序过后的各个单词为key，以字符串向量（vector<string>)为value，
        // 存储各个字符数量相同给的字符串(anagram)
        map<string, vector<string>> anagram;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());           // 对str内部进行排序
            if (anagram.find(str) == anagram.end()) // 若无法在哈希表中找到映射
            {
                vector<string> item; // 设置一个空的字符串向量
                anagram[str] = item; // 以排序后的strs[i]作为key
            }
            anagram[str].push_back(strs[i]); // 在对应的字符串向量中push结果
        }
        // map<string, vector<string>>::iterator it;
        vector<vector<string>> result;
        for (auto it = anagram.begin(); it != anagram.end(); it++)
        {
            result.push_back((*it).second); // it->second 也行
        }
        return result;
    }
};

/* 
 * 方法二：
 * 
 * 设置vector到字符串向量的哈希表anagram，遍历字符串strs中的单词strs[i]
 * 1）统计strs[i]中的各个字符数量，储存至vec。
 * 2）若vec未出现在anagram中，设置vec到一个空字符串向量的映射
 * 3）将strs[i]添加至字符串向量anagram[vec]中
 * 遍历哈希表anagram，将全部key对应的value添加至最终结果中
 *  
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> anagram;
        for (int i = 0; i < strs.size(); i++)
        {
            // 各个单词中字符出现的数量的vector到字符串向量（存储结果）的映射
            vector<int> vec(26, 0);
            change_to_vector(strs[i], vec);
            if (anagram.find(vec) == anagram.end())
            {
                vector<string> item;
                anagram[vec] = item;
            }
            anagram[vec].push_back(strs[i]);
        }

        // map<vector<int>, vector<string>>::iterator it;
        vector<vector<string>> result;
        for (auto it = anagram.begin(); it != anagram.end(); it++)
        {
            result.push_back((*it).second);
        }

        return result;
    }

private:
    void change_to_vector(string &str, vector<int> &vec)
    {
        for (int i = 0; i < str.length(); i++)
        {
            vec[str[i] - 'a']++;
        }
    }
};

// @lc code=end
