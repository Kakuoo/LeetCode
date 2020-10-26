#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;


// class Solution
// {
// public:
//     int CountGood(string str)
//     {
//         string gt = "Good";
//         int res = 0;
//         int p = 0;  // str
//         int q = 0;  // gt
//         while (p < str.size())
//         {
//             if (str[p] == gt[q])
//             {
//                 if (gt[q] == 'd')
//                 {
//                     res++;
//                     p++;
//                     q = 0;
//                 }
//                 else
//                 {
//                     p++;
//                     q++;
//                 }
//             }
//             else
//             {
//                 p++;
//             }
//         }
//         return res;
//     }
// };

// int main()
// {
//     // string str = "ggoodood";
//     string str = "Goo23good Gooddd";
//     // string str = "GoodoodGGoooddjfhjdGGooojdkdggggGoood0123\n";
//     // cin >> str;

//     int res = 0;
//     Solution s;
//     res = s.CountGood(str);
//     cout << res << endl;
// }

// class Solution
// {
// public:
//     typedef long long LL;
//     LL CountNumbers(vector<int> &nums)
//     {
//         if (nums.size() == 0)
//             return 0;

//         unordered_map<int, int> record;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             record[nums[i]]++;
//         }

//         int max_depth = *max_element(nums.begin(), nums.end()); // 所有节点中的最大深度
//         return CountNumbersCore(record, max_depth);
//     }

// private:
//     LL CountNumbersCore(unordered_map<int, int> &record, int max_depth)
//     {
//         LL res = 1;
//         for (int i = 1; i <= max_depth; i++)
//         {
//             if (record[i] == 2 * record[i - 1])
//                 continue;
//             else
//             {
//                 // 若该层节点不满，则需排列组合
//                 // 若上一层节点总数的2倍为n，当前层节点数为m，则该层可能情况为res = res + C_{n}^{m}
//                 int n = record[i - 1] * 2;
//                 int m = record[i];
//                 res *= C(n, m);
//             }
//         }
//         return res;
//     }

//     long long C(int n, int m)
//     {
//         n = n - m + 1;
//         long long ans = 1;
//         for (int i = 1; i <= m; ++i)
//         {
//             ans *= n++;
//             ans /= i;
//         }
//         return ans;
//     }
// };

// int main()
// {
//     int N = 0;
//     cin >> N;

//     int tmp = 0;
//     vector<int> vec;
//     while (N--)
//     {
//         cin >> tmp;
//         vec.push_back(tmp);
//     }

//     // 测试数据
//     // vector<int> vec = {1, 0, 2, 2}; // 2
//     // vector<int> vec = {0, 1, 2, 2, 3, 3, 3}; // 8

//     Solution s;
//     long long res = s.CountNumbers(vec);
//     cout << res << endl;
// }

// struct TreeNode
// {
//     int val;
//     TreeNode *parent;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), parent(nullptr), left(nullptr), right(nullptr) {}
// };

// TreeNode *GetNext(TreeNode *node)
// {
//     if (node == nullptr)
//         return nullptr;

//     TreeNode *p_next = nullptr;
//     if (node->right != nullptr)
//     {
//         TreeNode *p_right = node->right;
//         while (p_right->left != nullptr)
//             p_right = p_right->left;
//         p_next = p_right;
//     }
//     else if (node->parent != nullptr)
//     {
//         TreeNode *current = node;
//         TreeNode *parent = node->parent;
//         while (parent != nullptr && current = parent->right)
//         {
//             current = parent;
//             parent = parent->parent;
//         }
//         p_next = parent;
//     }
//     return p_next;
// }

// int main()
// {
//     int a = 1;
//     int x = 0b01111111111111111111111111111111;
//     cout << x << endl;
//     cout << (a << 31) - 1 << endl;

//     cout << INT_MAX << endl;

//     return 0;
// }

// class Solution
// {
// public:
//     string convert(string s, int num_cols)
//     {
//         vector<string> temp(num_cols); // 有几列就开几个字符串
//         string res;
//         if (s.empty() || num_cols < 1)
//             return res;
//         if (num_cols == 1)
//             return res;

//         bool is_X_top = true;
//         for (int i = 0; i < s.size();)
//         {
//             // 状态机
//             if (is_X_top == true)
//             {
//                 for (int j = 0; j <= num_cols / 2; j++)
//                 {
//                     if (s[i])
//                         temp[j].push_back(s[i++]);
//                     if (s[i] && j != num_cols / 2)
//                         temp[num_cols - 1 - j].push_back(s[i++]);
//                 }

//                 is_X_top = false;
//             }
//             else
//             {
//                 for (int j = (num_cols / 2) - 1; j > 0; j--)
//                 {
//                     if (s[i])
//                         temp[j].push_back(s[i++]);
//                     if (s[i] && j != num_cols / 2)
//                         temp[num_cols - 1 - j].push_back(s[i++]);
//                 }

//                 is_X_top = true;
//             }
//         }

//         for (int i = 0; i < temp.size(); i++)
//         {
//             res += temp[i];
//         }

//         return res;
//     }
// };

// int main()
// {
//     string str;
//     int cols;
//     cin >> str >> cols;
//     // str = "EVERYTHINGGOESWELL";
//     // cols = 5;

//     Solution s;
//     string res;
//     res = s.convert(str, cols);
//     cout << res << endl;

//     return 0;
// }

// class Solution
// {
// public:
//     bool lemonadeChange(const vector<int> &bills)
//     {
//         int five = 0, ten = 0;
//         for (const auto &bill : bills)
//             if (bill == 5)
//                 five++;
//             else if (bill == 10 && 0 < five)
//                 --five, ++ten;
//             else if (0 < ten && 0 < five)
//                 --five, --ten;
//             else if (2 < five)
//                 five -= 3;
//             else
//                 return false;
//         return true;
//     }
// };

// int main()
// {
//     vector<int> bills;
//     int bill = 0;
//     while (cin >> bill)
//     {
//         bills.push_back(bill);
//     }

//     Solution s;
//     bool res;
//     res = s.lemonadeChange(bills);
//     cout << boolalpha << res << endl;

//     return 0;
// }

// void swap_self(vector<int> &nums, int left, int right)
// {
//     int tmp = nums[left];
//     nums[left] = nums[right];
//     nums[right] = tmp;
// }

// int partition(vector<int> &array, int startIndex, int endIndex)
// {
//     //取第1个位置的元素作为基准元素
//     int pivot = array[startIndex];
//     int left = startIndex;
//     int right = endIndex;
//     while (left != right)
//     {
//         //控制right指针比较并左移
//         while (left < right && array[right] > pivot)
//         {
//             right--;
//         }
//         //控制left指针比较并右移
//         while (left < right && array[left] <= pivot)
//         {
//             left++;
//         }
//         //交换left和right指针所指向的元素
//         if (left < right)
//         {
//             int temp = array[left];
//             array[left] = array[right];
//             array[right] = temp;
//         }
//     }
//     //pivot和指针重合点交换
//     array[startIndex] = array[left];
//     array[left] = pivot;

//     return left;
// }

// int partition2(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[left];
//     int l = left;
//     int r = right;
//     while (l < r)
//     {
//         while (l <= r && nums[l] <= pivot)
//             l++;
//         while (l <= r && nums[r] > pivot)
//             r--;

//         cout << "Before swap: " << l << " " << r << endl;
//         if (l < r)
//             swap_self(nums, l, r);

//         cout << "After swap:" << endl;
//         for (int e : nums)
//         {
//             cout << e << " ";
//         }
//         cout << endl;
//     }

//     swap_self(nums, l, left);
//     return l;
// }

// template <typename T>
// int partition2_1(vector<T> &arr, int left, int right)
// {
//     swap(arr[rand() % (right - left + 1) + left], arr[left]);

//     T pivot = arr[left];
//     int i = left + 1;
//     int j = right;
//     while (true)
//     {
//         while (i <= right && arr[i] < pivot)
//             i++;
//         while (j >= left + 1 && arr[j] > pivot)
//             j--;

//         if (i > j)
//             break;

//         swap(arr[i], arr[j]);
//         i++;
//         j--;
//     }

//     swap(arr[i - 1], arr[left]);
//     return i - 1;
// }

// template <typename T>
// int partition1_4(vector<T> &nums, int left, int right)
// {
//     swap(nums[left], nums[rand() % (right - left + 1) + left]);

//     T pivot = nums[left];
//     int i = left + 1;
//     int j = right;
//     while (true)
//     {
//         while (i <= right && nums[i] < pivot)
//             i++;
//         while (j >= left + 1 && nums[j] > pivot)
//             j--;

//         if (i > j)
//             break;

//         swap(nums[i], nums[j]);
//         i++;
//         j--;
//     }

//     swap(nums[j], nums[left]);
//     return j;
// }

// template <typename T>
// int partition1_1(vector<T> &nums, int left, int right)
// {
//     swap(nums[left], nums[rand() % (right - left + 1) + left]);

//     T pivot = nums[left];
//     int mark = left;
//     for (int i = left + 1; i <= right; i++)
//     {
//         if (nums[i] < pivot)
//         {
//             swap(nums[i], nums[mark + 1]);
//             mark++;
//         }
//     }

//     swap(nums[left], nums[mark]);
//     return mark;
// }

// void QuickSort(vector<int> &nums, int left, int right)
// {
//     if (left >= right)
//         return;

//     int pivot_idx = partition1_4(nums, left, right);
//     QuickSort(nums, left, pivot_idx - 1);
//     QuickSort(nums, pivot_idx + 1, right);
// }

// int main()
// {
//     vector<int> nums = {7, 3, 2, 6, 8, 1, 9, 5, 4, 6, 10, 6, 3};
//     vector<int> nums11 = {7, 3, 2, 6, 8};
//     QuickSort(nums, 0, nums.size() - 1);

//     for (int e : nums)
//     {
//         cout << e << " ";
//     }
//     cout << endl;

//     return 0;
// }
// int count_score(string str)
// {
//     int res = 0;
//     for (char e : str)
//     {
//         res += towlower(e) - 97;
//     }
//     return res;
// }

// int main()
// {
//     string str;
//     int judge = 0;
//     cin >> str;
//     judge = count_score(str);

//     int N = 5;
//     int score = 0;
//     vector<pair<string, int>> name;
//     while (N--)
//     {
//         cin >> str;
//         score = count_score(str);
//         name.push_back(make_pair(str, score));
//     }

//     int distance = INT_MAX;
//     string res = "";
//     for (int i = 0; i < name.size(); i++)
//     {
//         int tmp = abs(name[i].second - judge);
//         if (distance >= tmp)
//         {
//             distance = tmp;
//             res = name[i].first;
//         }

//     }
//     cout << "Best answer: " << res << endl;

//     return EXIT_SUCCESS;
// }

// void BubbleSort(vector<int> nums)
// {
//     bool is_change = false;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (nums[j] > nums[j + 1])
//             {
//                 swap(nums[j], nums[j + 1]);
//             }
//         }

//         for (int e : nums)
//         {
//             cout << e << " ";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     // vector<int> vec = {2, 21, 9, 8, 16, 3, 7};
//     // BubbleSort(vec);
//     // int h = 1;
//     // int h_bak = 1;
//     // while (h <= 41)
//     // {
//     //     h_bak = h;
//     //     h = h * 3 + 1;
//     // }
//     // cout << h << endl;
//     // cout << h_bak << endl;

//     int a = 4;
//     cout << (a <<= 1) << endl;
//     return 0;
// }

// class KnapSack
// {
// public:
//     int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
//     {
//         assert(w.size() == v.size());
//         int n = w.size();

//         vector<vector<int>> dp(n, vector<int>(C + 1, -1));

//         // 第一行，以背包容量为列，以当前可选物品的个数为行
//         for (int j = 0; j <= C; j++) // j 代表当前状态背包容量是多少
//         {
//             dp[0][j] = (j >= w[0]) ? v[0] : 0;
//         }

//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j <= C; j++)
//             {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= w[i])
//                     dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
//             }
//         }

//         return dp[n - 1][C];
//     }
// };

// class KnapSack
// {
// public:
//     int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
//     {
//         assert(w.size() == v.size());
//         int n = w.size();
//         if (n == 0 || C == 0)
//             return 0;

//         vector<int> dp(C + 1, -1);

//         // 第一行，以背包容量为列，以当前可选物品的个数为行
//         for (int j = 0; j <= C; j++) // j 代表当前状态背包容量是多少
//         {
//             dp[j] = (j >= w[0]) ? v[0] : 0;
//         }

//         for (int i = 1; i < n; i++)
//         {
//             // for (int j = C; j >= w[i]; j--)
//             // {
//             //     if (j >= w[i])
//             //         dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
//             // }

//             for (int j = w[i - 1]; j <= C; j++)
//             {
//                 dp[j] = max(dp[j], dp[j - w[i-1]] + v[i-1]);
//             }
//         }

//         return dp[C];
//     }
// };

// int main()
// {
//     int C = 0; // 总预算, 即背包容量
//     int N = 0; // 物资种类, 即dp中的状态序列
//     cin >> C >> N;

//     vector<int> price(N, 0); // 商品价格
//     vector<int> value(N, 0);  // 商品使用价值

//     int p = 0, v = 0;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> p >> v;
//         price[i] = p;
//         value[i] = v;
//     }

//     KnapSack k;
//     int res = k.KnapSack01(price, value, C);
//     cout << res << endl;
//     return 0;
// }

// struct Interval
// {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

// bool compare1(const Interval &a, const Interval &b)
// {
//     if (a.start != b.start)
//         return a.start < b.start;
//     return a.end < b.end;
// }

// bool compare2(const Interval &a, const Interval &b)
// {
//     if (a.end != b.end)
//         return a.end < b.end;
//     return a.start < b.start;
// }

// class Solution
// {
// public:
//     int EraseOverlapIntervals(vector<Interval> &intervals)
//     {
//         if (intervals.size() == 0)
//             return 0;

//         // 前面的区间结束的越早，留给后面区间的空间就越大
//         // 每次选择结尾最早的区间，且和前一个区间不重叠的区间
//         // 按照区间的结尾进行排序
//         sort(intervals.begin(), intervals.end(), compare2);

//         int res = 1;
//         int prev = 0;
//         for (int i = 1; i < intervals.size(); i++)
//         {
//             if (intervals[i].start >= intervals[prev].end)
//             {
//                 res++;
//                 prev = i;
//             }
//         }
//         return intervals.size() - res;
//     }
// };

// class Solution
// {
// public:
//     int EraseOverlapIntervals(vector<Interval> &intervals)
//     {
//         if (intervals.size() == 0)
//             return 0;

//         sort(intervals.begin(), intervals.end(), compare1);

//         // dp[i]表示使用intervals[0, ..., i]的区间能构成的最长不重叠区间
//         vector<int> dp(intervals.size(), 1);
//         for (int i = 1; i < intervals.size(); i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 if (intervals[i].start >= intervals[j].end)
//                 {
//                     dp[i] = max(dp[i], 1 + dp[j]);
//                 }
//             }
//         }

//         int res = 0;
//         for (int e : dp)
//         {
//             res = max(res, e);
//         }

//         return intervals.size() - res;
//     }
// };

// class Solution
// {
// public:
//     int FindContentChildren(vector<int> &g, vector<int> &s)
//     {
//         sort(g.begin(), g.end(), greater<int>());
//         sort(s.begin(), s.end(), greater<int>());

//         int si = 0, gi = 0; // 指向最贪心的小朋友
//         int res = 0;
//         while (gi < g.size() && si < s.size())
//         {
//             if (s[si] >= g[gi])
//             {
//                 res++;
//                 si++;
//                 gi++;
//             }
//             else
//             {
//                 gi++;
//             }
//         }
//         return res;
//     }
// };

// int main()
// {
//     int n, m, q;
//     cin >> n >> m >> q;

//     // 初始化海岛
//     char tmp;
//     vector<vector<char>> record(n, vector<char>(m, '0'));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> tmp;
//             record[i][j] = tmp;
//         }
//     }

//     // 初始化询问
//     int bx = 0, by = 0, ex = 0, ey = 0;
//     vector<vector<int>> query;
//     for (int i = 0; i < q; i++)
//     {
//         cin >> bx >> by >> ex >> ey;
//         vector<int> tmp = {bx, by, ex, ey};
//         query.push_back(tmp);
//     }

//     vector<int> res(query.size());

//     //////////////////////////

//     // 算法实现

//     ////////////////////////////

//     // 打印结果
//     for (int e : res)
//     {
//         cout << e << endl;
//     }

//     return 0;
// }

// int main()
// {
//     string str;
//     cin >> str;
//     assert(str.size() > 0);

//     string res = "";
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= '0' && str[i] <= '9')
//         {
//             res += str[i];
//         }
//     }

//     cout << res << endl;
// }

// //矩阵位置坐标
// struct Rect
// {
//     int left_right_x;      //矩形左上角x坐标
//     int left_right_y;      //矩形左上角y坐标
//     int width;  //矩形宽度
//     int height; //矩形高度
//     Rect(int x, int y, int width, int height)
//         : left_right_x(x), left_right_y(y), width(width), height(height) {}
// };

// /**
//  * @brief 判断两个轴对齐的矩形是否重叠
//  * @param rect1 第一个矩阵的位置
//  * @param rect2 第二个矩阵的位置
//  * @return 两个矩阵是否重叠（边沿重叠，也认为是重叠）
//  */
// bool IsOverlap(const Rect &rect1, const Rect &rect2)
// {
//     if (rect1.left_right_x + rect1.width > rect2.left_right_x &&
//         rect2.left_right_x + rect2.width > rect1.left_right_x &&
//         rect1.left_right_y + rect1.height > rect2.left_right_y &&
//         rect2.left_right_y + rect2.height > rect1.left_right_y)
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     int rect1_lb_x = 0, rect1_lb_y = 0, rect1_rt_x = 0, rect1_rt_y = 0;  // rect1 (x1, y1), (x2, y2)
//     int rect2_lb_x = 0, rect2_lb_y = 0, rect2_rt_x = 0, rect2_rt_y = 0;  // rect2 (x1, y1), (x2, y2)
//     int rect1_w = 0, rect1_h = 0;  // rect1 width, height
//     int rect2_w = 0, rect2_h = 0;  // rect2 width, height

//     cin >> rect1_lb_x >> rect1_lb_y >> rect1_rt_x >> rect1_rt_y;
//     cin >> rect2_lb_x >> rect2_lb_y >> rect2_rt_x >> rect2_rt_y;

//     rect1_w = rect1_rt_x - rect1_lb_x;
//     rect1_h = rect1_rt_y - rect1_lb_y;
//     rect2_w = rect2_rt_x - rect2_lb_x;
//     rect2_h = rect2_rt_y - rect2_lb_y;

//     Rect rect1(rect1_lb_x, rect1_lb_y + rect1_h, rect1_w, rect1_h);
//     Rect rect2(rect2_lb_x, rect2_lb_x + rect2_h, rect2_w, rect2_h);
//     string response = IsOverlap(rect1, rect2) ? "Overlap" : "Not Overlap";
//     cout << response << endl;

//     return EXIT_SUCCESS;
// }

// #include <stdio.h>
// using namespace std;

// struct Student  // class -> struct
// {
//     const char *name;
//     int age;
// };

// int main()
// {
//     Student students[] = {
//         {"Tom", 12},
//         {"Jerry", 10},
//         {nullptr, 0}
//     };

//     Student *p = students;

//     while (p)  // 循环需要终止条件，p在遍历完结构体成员后，依然可能指向有值的地址
//     {
//         printf("{\"name\", \"%s, \"age\".%d}\n", p->name, p->age);
//         p++;
//     }
// }

// #include <iostream>
// #include <string.h>
// #include <string>
// #include <cmath>
// using namespace std;

// class Book
// {
// public:
//     Book(const char *pTitle)
//     {

//         m_pTitle = new char[strlen(pTitle) + 1];
//         strcpy(m_pTitle, pTitle);
//     }

//     ~Book()
//     {
//         delete m_pTitle;
//     }

//     void Print() const
//     {
//         std::cout << m_pTitle << std::endl;
//     }

// private:
//     char *m_pTitle;
// };

// int main()
// {
//     char title[60];
//     const char *b = title;
//     char *c;
//     std::string str = "test";

//     b = "good";
//     // c = <const_cast><char *>(str.c_str());

//     std::cout << "Enter book title";
//     std::cin >> title;
//     Book book(title);
//     book.Print();
//     return 0;
// }

// int main()
// {
//     char title[60] = "first test";
//     const char *b = title;
//     cout << b << endl;
//     char *c;
//     string str = "string test";

//     b = "good change";
//     cout << b << endl;

//     for (int i = 0; i < str.size(); i++)
//     {
//         title[i] = str[i];
//     }
//     cout << title << "!!!" << endl;

//     // c = const_cast<char *> (b);
//     c = const_cast<char *>(str.c_str());

//     strncpy(title, b, 20);
//     cout << title << endl;

//     // b = str.c_str();
//     // c = const_cast<char *>(str.c_str());
// }