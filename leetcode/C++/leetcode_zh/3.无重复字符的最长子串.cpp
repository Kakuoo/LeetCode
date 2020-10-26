/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.85%)
 * Likes:    3439
 * Dislikes: 0
 * Total Accepted:    422.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;

/**
 * 字符集：字母？数字+字母？ASCII？
 * 大小写敏感？
 * 是否有空解，多解？
 */

/*
 * 方法：双指针扫描字符串（双指针维护窗口/滑块）
 * 
 * 优化目标从暴力解法O(n^2)到O(n)，中间没有优化至O(nlogn)的条件
 * 所以需要将两重循环的枚举扫描修改为一层循环扫描
 * 
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        int left = 0;
        int right = -1;
        char record[256] = {0};
        while (left < s.size())
        {
            if (right + 1 < s.size() && record[s[right + 1]] == 0)
            {
                right++;
                record[s[right]]++;
            }
            else
            {
                record[s[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
        }

        return len;
    }
};

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int begin = 0;  // 窗口的头指针
//         int result = 0;
//         string word = "";
//         int char_map[128] = {0};
//         for (int i = 0; i <s.length(); i++)
//         {
//             char_map[s[i]]++;
//             if (char_map[s[i]] == 1)
//             {
//                 word += s[i];
//                 if (result < word.length())
//                 {
//                     result = word.length();
//                 }
//             }
//             else
//             {
//                 // 将重复的字符s[i]删去
//                 while (begin < i && char_map[s[i]] > 1)
//                 {
//                     char_map[s[begin]]--;
//                     begin++;
//                 }
//                 word = "";  // 重新更新word
//                 for (int j = begin; j<=i;j++)
//                 {
//                     word += s[j];
//                 }
//             }
//         }
//         return result;
//     }
// };
// @lc code=end
