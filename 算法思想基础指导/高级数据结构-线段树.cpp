/**
 * 线段树：（segment tree）
 * 
 * 一种按二叉树的形式存储数据的机构，每个节点保存的是数组里某一段区间的和
 * 叶子节点保存的是每个元素的值
 * 
 * 一种平衡二叉搜索树（完全二叉树，除了最后一层，其他层均是满的二叉树），
 * 将一个线段区间分成一些单元区间。对于线段树中的每一个非叶子节点[a, b]，
 * 其左子树表示的区间为[a, (a+b)/2]，右子树表示区间为[(a+b)/2 + 1, b]，
 * 最后的叶子节点数目为N，与数组下标对应。
 * 
 * 线段树一般包括建立、查询、插入、更新等操作，
 * 建立规模为N的时间复杂度是O(nlogn)，其他操作时间复杂度为O(logn)
 * 适合频繁的更新数组元素并求和的数据结构
 * 更新元素 O(logn) 对数组的求和 O(logn)
 * 复杂度即为遍历树的高度O(logn)
 * 
 * 根节点下标为0，设某个节点的下标为i，则它的左孩子下标为2*i+1，右孩子下标为2*i+2
 * 
 */


#include <vector>
#include <iostream>
using namespace std;

/**
 *  线段树的构造
 * 线段树数组value（每个节点都存储其左右区间的和），原始数组nums，pos为value的数组下标
 * 
 * 例如：将数组[0, 1, 2, 3, 4, 5]保存在存储区间和的线段树上
 * nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
 * value = [15, 3, 12, 1, 2, 7, 5, 0, 1, 0, 0, 3, 4]
 * 
 */

void build_segment_tree(vector<int> &value,
                        vector<int> &nums,
                        int pos, int left, int right)
{
    if (left == right)
    {
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, pos * 2 + 1, left, mid);
    build_segment_tree(value, nums, pos*2 + 2, mid + 1, right);
    value[pos] = value[pos*2 + 1] + value[pos*2 + 2];   // 代表左右子树区间值的和
}

// 线段树的遍历
void print_segment_tree(vector<int> &value,
                        int pos, int left, int right, int layer)
{
    for (int i = 0; i < layer; ++i)
    {
        printf("---");
    }
    printf("[%d, %d][%d] : %d\n", left, right, pos, value[pos]);
    if (left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
    print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer + 1);
}

// 线段树的求和
// 要么完全覆盖，要么完全无交集，算法复杂度O(logn)
// 线段树数组value，当前线段（节点）在线段树数组（value）中的下标pos
// 当前线段的左端点left，右端点right， 待求和区间的左端点qleft，右端点qright
int sum_range_segment_tree(vector<int> &value,
                           int pos, int left, int right,
                           int qleft, int qright)
{
    if (qright < left || qleft > right)
    {
        return 0;
    }
    if (qleft <= left && qright >= right)   // 如果为 if (left == right) 则复杂度稍高，不够简洁
    {
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright) +
           sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
}

/**
 * 线段树的更新
 * 
 * 如果当前访问节点为线段树叶节点，且为待更新数组的洗标index时，更新其值为new_value
 * 
 */
void update_segment_tree(vector<int> &value,
                         int pos, int left, int right,
                         int index, int new_value)
{
    if (left == right == index)
    {
        value[pos] = new_value;
        return;
    }
    int mid = (left + right) / 2;
    if (index <= mid)
    {
        // 递归更新左子树
        update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
    }
    else
    {
        // 递归更新右子树
        update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
    }
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

// leetcode 307,数组可修改
class NumArray1
{
public:
    NumArray1(vector<int> nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        // 一般线段树数组大小是原数组大小长度的4倍
        int n = nums.size() * 4;
        for (int i = 0; i < n; ++i)
        {
            value_.push_back(0);
        }
        build_segment_tree(value_, nums, 0, 0, nums.size() - 1);
        right_end_ = nums.size() - 1;
    }
    void update(int i, int val)
    {
        update_segment_tree(value_, 0, 0, right_end_, i, val);
    }
    int sumRange(int i, int j)
    {
        return sum_range_segment_tree(value_, 0, 0, right_end_, i, j);
    }

private:
    vector<int> value_;
    int right_end_; // 线段的右端点，即为数组长度-1
};
