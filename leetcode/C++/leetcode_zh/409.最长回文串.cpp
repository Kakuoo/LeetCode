/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (51.81%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 81.7K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int char_map[128] = {0}; // 字符哈希
        int max_len = 0;         // 回文串偶数部分的最大长度
        int center_flag = 0;     // 是否有中心点
        for (int i = 0; i < s.length(); i++)
        {
            // Insert(char_map, s[i], 128);
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; i++)
        {
            if (char_map[i] % 2 == 0)
            {
                max_len += char_map[i];
            }
            else
            {
                max_len += char_map[i] - 1;    // 若某字符是奇数个，则丢弃一个，其余的使用在回文串里
                center_flag = 1;
            }
        }
        return max_len + center_flag;
    }
};

// private:
//     int set_hash_func(int key, int table_len)
//     {
//         return key % table_len;
//     }

//     void Insert(ListNode *hash_table[], ListNode *node, int tabel_len)
//     {
//         int hash_key = set_hash_func(node->val, tabel_len);
//         node->next = hash_table[hash_key];
//         hash_table[hash_key] = node;
//     }

//     void Search(ListNode *hash_table[], int value, int table_len)
//     {
//         int hash_key = set_hash_func(value, table_len);
//         ListNode *head = hash_table[hash_key];
//         while (head)
//         {
//             if (head->val == value)
//             {
//                 return true;
//             }
//             head = head->next;
//         }
//         return false;
//     }
// };
// @lc code=end
