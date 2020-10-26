/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        
        while (up <= down && left <= right)
        {
            for (int j = left; j <= right; j++)
                res.push_back(matrix[up][j]);
            up++;

            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            right--;
            
            for (int j = right; j >= left && up <= down; j--)
                res.push_back(matrix[down][j]);
            down--;

            for (int i = down; i >= up && left <= right; i--)
                res.push_back(matrix[i][left]);
            left++;
        }

        return res;        
    }
};

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};
        
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        while (true)
        {
            // 最上一行
            for (int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            
            // 最右一列
            if (++up > down)
                break;
            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            
            // 最下一行
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
                res.push_back(matrix[down][i]);

            // 最左一列
            if (--down < up)
                break;
            for (int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);

            if (++left > right)
                break;
        }
        return res;
    }
};

// @lc code=end
