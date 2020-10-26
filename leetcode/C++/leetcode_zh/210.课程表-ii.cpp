/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
    }
};

int main()
{
    // std::string strvalues = "1, 2, -1, 1";
    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<int> projects;
    int tmp_i;
    char tmp_c;
    while (ss >> tmp_i)
    {
        ss >> tmp_c;
        projects.push_back(tmp_i);
        // cout << tmp_i << " " << tmp_i << endl;
    }

    // 构建邻接表
    int num_courses = projects.size();
    vector<vector<int>> prerequisites;


    return 0;
}
// @lc code=end
