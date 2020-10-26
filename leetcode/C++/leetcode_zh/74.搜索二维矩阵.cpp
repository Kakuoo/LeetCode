/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

// 二分查找法
// 8ms, runtime 86%
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int n = matrix[0].size();
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[mid / n][mid % n] < target)
            {
                left = mid + 1;
            }
            else if (matrix[mid / n][mid % n] > target)
            {
                right = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

// 从左下角至右上角
// 8ms, runtime 86%
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int x = matrix.size() - 1, y = 0;
        while (x >= 0 && y <= matrix[0].size() - 1)
        {
            if (matrix[x][y] < target)
                y++;
            else if (matrix[x][y] > target)
                x--;
            else
                return true;
        }
        return false;
    }
};

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         if (matrix.size() == 0)
//             return false;

//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[i].size(); j++)
//             {
//                 if (matrix[i][j] == target)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// @lc code=end
