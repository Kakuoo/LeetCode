/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include <vector>
using namespace std;


// 方法一 回溯法
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> item;
        vector<vector<int>> result;
        result.push_back(item);
        generate(0, nums, item, result);

        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result)
    {
        if (i >= nums.size())
            return;
        
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }
};

// 方法二 位运算法
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        int all_set = 1 << nums.size(); // 1 << n 即将1向左移n位，2^n
        for(int i = 0;i < all_set; i++)
        {
            vector<int> item;
            for (int j = 0; j < nums.size();j++)
            {
                // 构造数字i代表的集合，各元素存储至item
                // 整数i代表从0至2^n-1这2^n个集合
                // (1<<j)即为构造nums数组的第j个元素
                // 若i&(1<<j)为真则nums[j]放入item
                if ( i &(1<<j)) 
                {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }

};

// @lc code=end
