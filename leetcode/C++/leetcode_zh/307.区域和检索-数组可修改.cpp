/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (53.50%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 16.6K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
 * 
 * 示例:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 说明:
 * 
 * 
 * 数组仅可以在 update 函数下进行修改。
 * 你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

// 方法 ：构造线段树
// 原始数组nums，线段树数组value（每个节点都存储其左右区间的和），pos为value的数组下标
/**
 * 例如：将数组nums = [0, 1, 2, 3, 4, 5]保存在存储区间和的线段树上
 *    id = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
 * value = [15, 3, 12, 1, 2, 7, 5, 0, 1, X, X, 3, 4]
 * value = [15, 3, 12, 1, 2, 0, 1, 2, 3, 4, 5, 6]
 */


// 下述方法完全没看懂
class NumArray
{
private:
    int n;  // 初始化为nums.size()
    vector<int> tree;

public:
    NumArray(vector<int> &nums) : n(nums.size()), tree(n << 1)
    {
        for (int i = n, j = 0; i < n << 1; ++i, ++j)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }
    void update(int pos, int val)
    {
        pos += n;
        val -= tree[pos];
        while (pos)
        {
            tree[pos] += val;
            pos >>= 1;
        }
    }
    int sumRange(int left, int right)
    {
        int res = 0;
        for (left += n, right += n; left <= right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                res += tree[left++];
            if (!(right & 1))
                res += tree[right--];
        }
        return res;
    }
};

// 测试数据 ["NumArray","sumRange","update","sumRange"]\n[[[0,1,2,3,4,5]],[2,5],[2,10],[2,5]]
// ["NumArray","sumRange","update","sumRange"]
// [[[-1]],[0,0],[0,1],[0,0]]
// 第3个case runtime error

// class NumArray
// {
// public:
//     NumArray(vector<int> &nums)
//     {
//         if (nums.size() == 0)
//             return;
//         int n = nums.size() * 4;
//         for (int i = 0; i < n; ++i)
//         {
//             value_.push_back(0);
//         }
//         right_end_ = nums.size() - 1;
//         build_segment_tree(nums, value_, 0, 0, right_end_);
//     }

//     void update(int i, int val)
//     {
//         update_segment_tree(value_, 0, 0, right_end_, i, val);
//     }

//     int sumRange(int i, int j)
//     {
//         return sum_range_segment_tree(value_, 0, 0, right_end_, i, j);
//     }

// private:
//     vector<int> value_;
//     int right_end_;
//     void build_segment_tree(vector<int> &nums, vector<int> &value,
//                             int pos, int left, int right)
//     {
//         if (left == right)
//         {
//             value[pos] = nums[left];
//             return;
//         }
//         int mid = (left + right) / 2;
//         build_segment_tree(nums, value, pos * 2 + 1, left, mid);
//         build_segment_tree(nums, value, pos * 2 + 2, mid + 1, right);
//         value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
//     }

//     void update_segment_tree(vector<int> &value, int pos,
//                              int left, int right, int index, int new_value)
//     {
//         if (left == right == index)
//         {
//             value[pos] = new_value;
//             return;
//         }
//         int mid = (left + right) / 2;
//         if (index <= mid)
//             update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
//         else
//             update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
//         value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
//     }

//     int sum_range_segment_tree(vector<int> &value, int pos,
//                                int left, int right, int qleft, int qright)
//     {
//         if (qleft > right || qright < left)
//             return 0;
//         if (qleft <= left && qright >= right)
//         {
//             return value[pos];
//         }
//         int mid = (left + right) / 2;
//         return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright) +
//                sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
//     }
// };

/**
 * 最睿智，最简单的方法
 * 264ms，runtime 19.6%
 */

// class NumArray
// {
// public:
//     NumArray(vector<int> &nums)
//     {
//         nums_copy = nums;
//     }

//     void update(int i, int val)
//     {
//         nums_copy[i] = val;
//     }

//     int sumRange(int i, int j)
//     {
//         int sum = 0;
//         for (int k = i; k <= j; ++k)
//         {
//             sum += nums_copy[k];
//         }
//         return sum;
//     }

// private:
//     vector<int> nums_copy;
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
