/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (43.59%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 33.6K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

/* 
 * 方法一：枚举
 *
 * 长度10为常数级，可尝试枚举所有子串，将其插入到哈希map中，并记录子串数量
 * 遍历哈希map，将所有出现超过1次的子串存储到结果中。算法复杂度O(n)
 * 
 */

// class Solution
// {
// public:
//     vector<string> findRepeatedDnaSequences(string s)
//     {
//         map<string, int> word_map;
//         vector<string> result;
//         for (int i = 0; i < s.length(); i++)
//         {
//             string word = s.substr(i, 10);
//             if (word_map.find(word) != word_map.end())
//             {
//                 word_map[word] += 1;
//             }
//             else
//             {
//                 word_map[word] = 1;
//             }
//         }
//         // map<string, int>::iterator it;
//         for (auto it = word_map.begin(); it != word_map.end(); it++)
//         {
//             if (it->second > 1)
//             {
//                 result.push_back(it->first);
//             }
//         }
//         return result;
//     } 
// };

/*
 * 方法二：
 * 将长度为10的DNA序列进行整数编码
 * ['A', 'C', 'G', 'T']分别用[0,1,2,3]（二进制形式（00,01,10,11））所表示，
 * 故长度为10的DNA序列可以用20个比特位的整数所表示
 * 
 */

/*
 * 1.设置全局整数哈希int_hash_map[1048675 = 2^20]，表示所有长度为10的DNA子序列；
 * 2.将DNA字符串的前10个字符使用左移位运算符转换为整数key，g_hash_map[key]++；
 * 3.从DNA的第11位字符起，按顺序遍历各字符，遇到1个字符即将key右移2位（去掉最低位），
 * 并且将新的DNA字符s[i]，转换为整数后，或到最高位（第19、20位），g_hash_map[key]++；
 * 4.遍历哈希表g_hash_map，若g_hash_map[i]>1，将i从低到高位转换为10个字符的DNA序列，push至结果数组
 */

//////////////////////////
// 本方法答案有问题！！！
//////////////////////////
// int g_hash_map[1048675] = {0}; // 哈希表太大，需要全局数组

// string change_int_to_DNA(int DNA)
// {
//     static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
//     string str;
//     for (int i = 0; i < 10; i++) // 将一个长度为10的数组，从整数转化为字符串
//     {
//         str += DNA_CHAR[DNA & 3];
//         DNA = DNA >> 2;
//     }
//     return str;
// }

// class Solution
// {
// public:
//     vector<string> findRepeatedDnaSequences(string s)
//     {
//         vector<string> result;
//         if (s.length() < 10)
//         {
//             return result;
//         }
//         for (int i = 0; i < 1048675; i++)   // 每次调用需更新全局数组
//         {
//             g_hash_map[i] = 0;
//         }
//         int char_map[128] = {0};
//         char_map['A'] = 0;
//         char_map['C'] = 1;
//         char_map['G'] = 2;
//         char_map['T'] = 3;
//         int key = 0;
//         for (int i = 9; i >= 0;i--)
//         {
//             key = (key << 2) + char_map[s[i]];
//         }
//         g_hash_map[key] = 1;
//         for (int i = 10; i < s.length(); i++)
//         {
//             key = key >> 2;
//             key = key |(char_map[s[i]]<18);
//             g_hash_map[key]++;
//         }
//         for (int i = 0; i < 1048675; i++)
//         {
//             if (g_hash_map[i] > 1)
//             {
//                 result.push_back(change_int_to_DNA(i));
//             }
//         }
//         return result;
//     }
// };
// @lc code=end
