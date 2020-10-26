/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * 进阶问题：
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法：
 * 排序 + 双指针
 * 
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优：
 * 哈希表（较小的数组进行哈希计数，然后在另一数组中根据哈希来寻找）
 * 
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中： 
 * 通过归并外排将两个数组排序后再使用排序双指针查找
 * 
 * 对应进阶问题三，如果内存十分小，不足以将数组全部载入内存，
 * 那么必然也不能使用哈希这类费空间的算法，只能选用空间复杂度最小的算法，即解法一。
 * 但是解法一中需要改造，一般说排序算法都是针对于内部排序，一旦涉及到跟磁盘打交道（外部排序），
 * 则需要特殊的考虑。归并排序是天然适合外部排序的算法，可以将分割后的子数组写到单个文件中，
 * 归并时将小文件合并为更大的文件。当两个数组均排序完成生成两个大文件后，
 * 即可使用双指针遍历两个文件，如此可以使空间复杂度最低。
 */


// runtime 12ms 65.8%
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
        }
        return res;
    }
};

// runtime 24ms 8.3%
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // 构建map
        map<int, int> record;
        for (int i = 0; i < nums1.size(); i++)
        {
            record[nums1[i]]++;
        }

        vector<int> res;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (record[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                record[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end
