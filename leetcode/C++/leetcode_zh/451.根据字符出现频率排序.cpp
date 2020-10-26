/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

// 利用lambda自定义排序
// runtime 764 ms 5.2%
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> record;
        for (auto e : s)
        {
            record[e]++;
        }

        sort(s.begin(), s.end(), [&](char &a, char &b) {return (record[a] > record[b]) || (record[a] == record[b] && a < b);});
        return s;
    }
};

// // 优先队列 速度最快 runtime: 16ms, 91.8%
// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         unordered_map<char, int> record;
//         for (auto e : s)
//         {
//             record[e]++;
//         }

//         priority_queue<pair<int, char>> Q;
//         for (auto e : record)
//         {
//             Q.push(make_pair(e.second, e.first));
//         }

//         string res;
//         while (!Q.empty())
//         {
//             auto tmp = Q.top();
//             while (tmp.first-- > 0)
//             {
//                 res += tmp.second;
//             }
//             // res.append(tmp.first, tmp.second);
//             // res.insert(res.end(), tmp.first, tmp.second);
//             Q.pop();
//         }
//         return res;
//     }
// };

// // 在vector中存储pair对，利用vector自定义排序
// // runtime 28 ms 58%
// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         unordered_map<char, int> record;
//         for (auto e : s)
//         {
//             record[e]++;
//         }
//         vector<pair<char, int>> vec;
//         for (auto e : record)
//         {
//             vec.push_back(e);
//         }

//         // 核心步骤，自定义排序lambda函数
//         sort(vec.begin(), vec.end(), [](const pair<char, int> &p1, const pair<char, int> &p2) {return p1.second > p2.second;});

//             string ret;
//         for (int i = 0; i < vec.size(); i++)
//         {
//             ret.append(vec[i].second, vec[i].first);
//         }
//         return ret;
//     }
// };

// // 每个字符出现次数不会超过字符串s长度，将字符添加到字符出现次数对应数组下标处，
// //然后从后向前遍历，如果对应下标不为空，则添加到结果集中。
// // runtime 52ms 15%
// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         // 构建哈希表
//         unordered_map<char, int> record;
//         for (auto e : s)
//         {
//             record[e]++;
//         }

//         // 构建数组vector用于存储字符出现的次数
//         string res;
//         vector<string> char_vec(s.size() + 1, "");
//         for (auto e : record)
//         {
//             // char_vec[e.second].insert(char_vec[e.second].begin(), e.second, e.first);
//             char_vec[e.second].append(e.second, e.first);
//         }

//         for (int i = s.size(); i > 0; i--)
//         {
//             if (!char_vec.empty())
//                 res += char_vec[i];
//         }
//         return res;
//     }
// };


// // @lc code=end
