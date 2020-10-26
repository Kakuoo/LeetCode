/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        assert(A.size() == B.size() && B.size() == C.size() && C.size() == D.size());

        unordered_map<int, int> record;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                record[A[i] + B[j]]++;
            }
        }

        int res = 0;
        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                if (record.find(0 - C[i] - D[j]) != record.end())
                {
                    res += record[0 - C[i] - D[j]];
                }
            }
        }
        return res;
    }
};

// liuyubobo: 寻找有多少种组合可以使得四数之和等于target
// class Solution
// {
// public:
//     int fourSumCount(vector<int> &A, vector<int> &B,
//                                      vector<int> &C, vector<int> &D, int target)
//     {
//         unordered_map<int, int> record;
//         for (int i = 0; i < C.size(); i++)
//         {
//             for (int j = 0; j < D.size(); j++)
//             {
//                 record[C[i] + D[j]]++;
//             }
//         }

//         int freq = 0;
//         for (int i = 0; i < A.size(); i++)
//         {
//             for (int j = 0; j < B.size(); j++)
//             {
//                 if (record.find(target - A[i] - B[j]) != record.end())
//                     freq += record[target - A[i] - B[j]];
//             }
//         }
//         return freq;
//     }
// };
// @lc code=end
