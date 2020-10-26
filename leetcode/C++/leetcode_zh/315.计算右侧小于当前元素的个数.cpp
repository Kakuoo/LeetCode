/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (37.25%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 34.7K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于
 * nums[i] 的元素的数量。
 * 
 * 示例:
 * 
 * 输入: [5,2,6,1]
 * 输出: [2,1,1,0] 
 * 解释:
 * 5 的右侧有 2 个更小的元素 (2 和 1).
 * 2 的右侧仅有 1 个更小的元素 (1).
 * 6 的右侧有 1 个更小的元素 (1).
 * 1 的右侧有 0 个更小的元素.
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

/* 
 * 方法一 二叉排序树
 * 将元素按照原数组逆置后的顺序插入到二叉排序树中，在元素插入中，计算已有多少个元素比当前插入元素小
 * 算法如下：
 * 设置变量count_small=0，记录在插入过程中，有多少个元素比插入节点值小；
 * 若待插入节点值小于等于当前节点node值，node->count++，递归将该节点插入到当前节点的左子树中
 * 若待插入节点值大于当前节点node值，node_small+=node->count+1（当前节点左子树数量+1），递归将该节点插入到当前节点的右子树中
 * 
 */

////////////////////////////////////////////
// 方法一有问题！！！！！！
///////////////////////////////////////////

// struct BSTNode
// {
// 	int val;
// 	int count;
// 	BSTNode *left;
// 	BSTNode *right;
// 	BSTNode(int x) : val(x), count(0), left(NULL), right(NULL) {}
// };

// class Solution
// {
// public:
// 	vector<int> countSmaller(vector<int> &nums)
// 	{
// 		vector<int> result;
// 		vector<BSTNode *> nodeVec; // 创建的二叉排序树节点池
// 		vector<int> count;		   // 记录从后向前插入的过程中，比当前节点值小的count_small数组
// 		for (int i = nums.size() - 1; i >= 0; i--)
// 		{
// 			nodeVec.push_back(new BSTNode(nums[i])); // 按照从后向前的顺序创建二叉排序树节点
// 		}
// 		count.push_back(0); // 第一个节点count_small=0
// 		for (int i = 1; i < nodeVec.size(); i++)
// 		{
// 			int count_small = 0;
// 			BST_insert(nodeVec[0], nodeVec[i], count_small);
// 			count.push_back(count_small);
// 		}
// 		for (int i = nodeVec.size(); i >= 0; i--)
// 		{
// 			delete nodeVec[i];
// 			result.push_back(count[i]); // 将count_small数组按照从后向前的顺序push进入result数组
// 		}
// 		return result;
// 	}

// private:
// 	void BST_insert(BSTNode *node, BSTNode *insertNode, int &countSmall)
// 	{
// 		if (insertNode->val <= node->val)
// 		{
// 			if (insertNode->val < node->val)
// 			{
// 				node->count++;
// 			}
// 			if (node->left)
// 			{
// 				BST_insert(node->left, insertNode, countSmall);
// 			}
// 			else
// 			{
// 				node->left = insertNode;
// 			}
// 		}
// 		else
// 		{
// 			countSmall += node->count + 1;
// 			if (node->right)
// 			{
// 				BST_insert(node->right, insertNode, countSmall);
// 			}
// 			else
// 			{
// 				node->right = insertNode;
// 			}
// 		}
// 	}
// };


/* 
 *方法二 利用归并的思想
 * 须使用O(nlogn)复杂度的算法
 * 68ms, Runtime 45.56%
 */

// class Solution
// {
// public:
// 	vector<int> countSmaller(vector<int> &nums)
// 	{
// 		vector<int> counts(nums.size(), 0);
// 		vector<pair<int, int>> vec;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			vec.push_back(make_pair(nums[i], i));
// 		}
// 		smallerNumber(vec, counts);
// 		return counts;
// 	}
// 	void smallerNumber(vector<pair<int, int>> &vec, vector<int> &count)
// 	{
// 		if (vec.size() < 2)
// 		{
// 			return;
// 		}
// 		int mid = vec.size() / 2;
// 		vector<pair<int, int>> sub_vec1;
// 		vector<pair<int, int>> sub_vec2;
// 		sub_vec1.assign(vec.begin(), vec.begin() + mid);
// 		sub_vec2.assign(vec.begin() + mid, vec.end());
// 		//sortTheOrder(sub_vec1, sub_vec2, vec);没有真理解递归的含义
// 		smallerNumber(sub_vec1, count);
// 		smallerNumber(sub_vec2, count);
// 		vec.clear();	// 此步非常重要
// 		sortTheOrder(sub_vec1, sub_vec2, vec, count);
// 	}
// 	void sortTheOrder(vector<pair<int, int>> &sub_vec1, vector<pair<int, int>> &sub_vec2,
// 					  vector<pair<int, int>> &vec, vector<int> &count)
// 	{
// 		int i = 0, j = 0;
// 		while (i != sub_vec1.size() && j != sub_vec2.size())
// 		{
// 			/*if (*iter1 <= *iter2)*/
// 			if (sub_vec1[i].first <= sub_vec2[j].first)
// 			{
// 				vec.push_back(sub_vec1[i]); //count[i] += j
// 				count[sub_vec1[i].second] += j;
// 				i++;
// 			}
// 			else
// 			{
// 				vec.push_back(sub_vec2[j]);
// 				j++;
// 			}
// 		}
// 		while (i != sub_vec1.size())
// 		{
// 			vec.push_back(sub_vec1[i]);
// 			count[sub_vec1[i].second] += j;
// 			i++;
// 		}
// 		while (j != sub_vec2.size())
// 		{
// 			vec.push_back(sub_vec2[j]);
// 			j++;
// 		}
// 	}
// };

///////////////////////////////////////////////////////////////////
/**
 * 方法三的另一种写法，略微改动
 * 100ms, Runtime 37.55%
 */
// class Solution
// {
// public:
// 	vector<int> countSmaller(vector<int> &nums)
// 	{
// 		vector<int> count(nums.size(), 0);
// 		vector<pair<int, int>> vec;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			vec.push_back(make_pair(nums[i], i));
// 		}
// 		merge_sort(vec, count);
// 		return count;
// 	}

// private:
// 	void merge_sort(vector<pair<int, int>> &vec, vector<int> &count)
// 	{
// 		if (vec.size() < 2)
// 		{
// 			return;
// 		}
// 		int mid = vec.size() / 2;
// 		vector<pair<int, int>> sub_vec1;
// 		vector<pair<int, int>> sub_vec2;
// 		for (int i = 0; i < mid; i++)
// 		{
// 			sub_vec1.push_back(vec[i]);
// 		}
// 		for (int i = mid; i < vec.size(); i++)
// 		{
// 			sub_vec2.push_back(vec[i]);
// 		}
// 		merge_sort(sub_vec1, count);
// 		merge_sort(sub_vec2, count);
// 		vec.clear();
// 		merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
// 	}

// 	void merge_sort_two_vec(
// 		vector<pair<int, int>> &sub_vec1,
// 		vector<pair<int, int>> &sub_vec2,
// 		vector<pair<int, int>> &vec,
// 		vector<int> &count)
// 	{
// 		int i = 0;
// 		int j = 0;
// 		while (i < sub_vec1.size() && j < sub_vec2.size())
// 		{
// 			if (sub_vec1[i].first <= sub_vec2[j].first)
// 			{
// 				count[sub_vec1[i].second] += j;
// 				vec.push_back(sub_vec1[i]);
// 				i++;
// 			}
// 			else
// 			{
// 				vec.push_back(sub_vec2[j]);
// 				j++;
// 			}
// 		}
// 		for (; i < sub_vec1.size();i++)
// 		{
// 		    count[sub_vec1[i].second] +=j;
// 		    vec.push_back(sub_vec1[i]);
// 		}
// 		for (; j < sub_vec2.size();j++)
// 		{
// 		    vec.push_back(sub_vec2[j]);
// 		}
// 	}
// };

/* 
 * 方法三  偷懒的方法（高复杂度）
 * 232ms, Runtime 19.73%
 * lower_bound 返回大于等于val的第一个元素的迭代器位置
 */
// class Solution
// {
// public:
// 	vector<int> countSmaller(vector<int> &nums)
// 	{
// 		vector<int> temp;	// 插入排序数组
// 		vector<int> count(nums.size(), 0);
// 		for (int i = nums.size() - 1; i >= 0; i--)
// 		{
// 			vector<int>::iterator pos = lower_bound(temp.begin(), temp.end(), nums[i]);	// 返回大于等于nums[i]的下界
// 			count[i] = pos - temp.begin();
// 			temp.insert(pos, nums[i]);
// 		}
// 		return count;
// 	}
// };

/* 
 *方法四 暴力搜索，偷懒的方法 O(N^2)高复杂度
 * 	最后一个case时间复杂度超时！无法通过!
 */

// class Solution
// {
// public:
// 	vector<int> countSmaller(vector<int> &nums)
// 	{
// 		vector<int> result(nums.size(), 0);
// 		for (int i = 0; i < nums.size(); i++)
// 			for (int j = i + 1; j < nums.size(); j++)
// 			{
// 				if (nums[j] < nums[i])
// 					result[i]++;
// 			}
// 		return result;
// 	}
// };

// @lc code=end
