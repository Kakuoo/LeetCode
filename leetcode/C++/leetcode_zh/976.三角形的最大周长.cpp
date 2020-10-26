/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode-cn.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (54.56%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 26.6K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
 * 
 * 如果不能形成任何面积不为零的三角形，返回 0。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1,2]
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,1]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：[3,2,3,4]
 * 输出：10
 * 
 * 
 * 示例 4：
 * 
 * 输入：[3,6,2,3]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 1 <= A[i] <= 10^6
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <functional>
using namespace std;

// 不使用库函数sort，自写快排
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int len = A.size();
        for (int i = len - 1; i > 1; i--)
        {
            if (A[i] < A[i - 1] + A[i - 2])
            {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};


// 方法一
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0; i < A.size() - 2; ++i)
        {
            if (A[i] < A[i + 1] + A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};


// 方法二
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int len = A.size();
        for (int i = len - 1; i > 1; i--)
        {
            if (A[i] < A[i - 1] + A[i - 2])
            {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};


// 方法三
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        if (A.size() < 3)
            return 0;
        int res = 0;
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i > 1; --i)
        {
            if (is_triangle(A[i], A[i - 1], A[i - 2]))
            {
                int tmp = A[i] + A[i - 1] + A[i - 2];
                res = res > tmp ? res : tmp;
            }
        }
        return res;
    }

private:
    bool is_triangle(int a, int b, int c)
    {
        if (a + b > c && abs(a - b) < c)
        {
            return true;
        }
        else if (a + c > b && abs(a - c) < b)
        {
            return true;
        }
        else if (b + c > a && abs(b - c) < a)
        {
            return true;
        }
        return false;
    }
};

// @lc code=end
