/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

// 剪枝版本
// 16ms, runtime 92.21%
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        if (n <= 0 || k <= 0 || n < k)
            return res;
        
        vector<int> c;
        GenerateCombination(n, k, 1, c);
        return res;
    }

private:
    vector<vector<int>> res;

    // 求解C(n, k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void GenerateCombination(int n, int k, int start, vector<int> &c)
    {
        if (c.size() == k)
        {
            res.push_back(c);
            return;
        }

        // 还有 k-c.size() 个空位，所以[i, ..., n]中至少要有 k-c.size() 个元素
        // i 最多为 n - (k - c.size()) + 1 
        for (int i = start; i <= n - (k - c.size()) + 1; i++)
        {
            c.push_back(i);
            GenerateCombination(n, k, i + 1, c);

            // 回溯的过程，必须恢复c中的状态
            c.pop_back();
        }
        return;
    }
};


// 未剪枝版本
// 44ms，runtime 62.9%
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        if (n <= 0 || k <= 0 || n < k)
            return res;
        
        vector<int> c;
        GenerateCombination(n, k, 1, c);
        return res;
    }

private:
    vector<vector<int>> res;

    // 求解C(n, k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void GenerateCombination(int n, int k, int start, vector<int> &c)
    {
        if (c.size() == k)
        {
            res.push_back(c);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            c.push_back(i);
            GenerateCombination(n, k, i + 1, c);

            // 回溯的过程，必须恢复c中的状态
            c.pop_back();
        }
        return;
    }
};
// @lc code=end
