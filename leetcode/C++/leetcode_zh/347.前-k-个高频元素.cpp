/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.13%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 84.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * 优先级队列
 * 
 * topk （前k大）用小根堆，维护堆大小不超过 k 不即可。
 * 每次压入堆前和堆顶元素比较，如果比堆顶元素还小，直接扔掉，否则压入堆。
 * 检查堆大小是否超过 k，如果超过，弹出堆顶。复杂度是 nlogk
 * 
 * 避免使用大根堆，因为你得把所有元素压入堆，复杂度是 nlogn，
 * 而且还浪费内存。如果是海量元素，那就挂了。
 * 
 */

/**
 * map的底层实现是红黑树，已经排过序的数据结构，中序遍历可以得到有序遍历结果
 * unordered_map的底层实现是哈希表，无序容器，
 * 无论从插入，查找来说，unordered_map的效率更高一些
 * 空间复杂度方面：hash_map最低，unordered_map次之，map最大
 * 
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        using P = pair<int, int>;
        map<int, int> count_map;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        for (auto e : nums)
        {
            ++count_map[e];
        }
        for (auto &x : count_map)
        {
            // pair<int, int> pair;
            auto pair = make_pair(x.second, x.first);
            if (min_heap.size() == k)
            {
                // if (pair < min_heap.top()) continue;
                if (pair.first < min_heap.top().first) continue;
                min_heap.pop();
            }
            min_heap.push(move(pair));
        }
        vector<int> res(min_heap.size());
        int n = res.size();
        while (!min_heap.empty())
        {
            res[--n] = min_heap.top().second;
            min_heap.pop();
        }
        return res;
    }
};

// 直接将n个元素全部放入最大堆时间复杂度为O(nlogn)，不如上面的只放入k个的时间复杂度为O(nlogk)的效果好
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> res;
        unordered_map<int, int> hash_map;       //  pair<int, int>(nums[i], i)
        priority_queue<pair<int, int>> max_heap; // pair<int, int>(i, nums[i])
        for (auto e : nums)
        {
            ++hash_map[e]; // hash_map构建完成
        }
        for (auto m : hash_map)
        {
            // max_heap.push(pair<int, int>(-m.second, m.first));
            // max_heap.push(make_pair(-m.second, m.first));
            // max_heap.push(move(make_pair(-m.second, m.first)));
            pair<int, int> pair = make_pair(-m.second, m.first);    // 改成添加i.second的相反数
            max_heap.push(pair);
            if (max_heap.size() > k)
                max_heap.pop();
        }
        while (k--)
        {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
