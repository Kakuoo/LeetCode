/**
 * 归并排序
 * 将原问题拆解为数个子问题：
 * 分解时间：解决子问题时间 + 合并时间
 * 复杂度O(nlogn)
 * 
 */

#include <vector>
using namespace std;

void merge_sort_two_vec(vector<int> &sub_vec1, vector<int> &sub_vec2, vector<int> &vec)
{
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size())
    {
        if (sub_vec1[i] <= sub_vec2[j])
        {
            vec.push_back(sub_vec1[i]);
            i++;
        }
        else
        {
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    // 将sub_vec1或sub_vec2中剩余元素push进入vec中
    for (; i < sub_vec1.size(); ++i)    // while (i != sub_vec1.size())
    {
        vec.push_back(sub_vec1[i]);
    }
    for (; j < sub_vec2.size(); ++j)    // while (i != sub_vec1.size())
    {
        vec.push_back(sub_vec2[j]);
    }
}

void merge_sort(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        return;
    }
    int mid = vec.size() / 2;
    vector<int> sub_vec1;
    vector<int> sub_vec2;
    for (int i = 0; i < mid; ++i)
    {
        sub_vec1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); ++i)
    {
        sub_vec2.push_back(vec[i]);
    }
    merge_sort(sub_vec1);
    merge_sort(sub_vec2);
    vec.clear();
    merge_sort_two_vec(sub_vec1, sub_vec2, vec);
}