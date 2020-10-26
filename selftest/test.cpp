// #include <bits/stdc++.h>
#include <algorithm>
// #include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <string>
// #include <cstring>
// #include <iomanip>
// #include <sstream>
// #include <initializer_list>
// #include <utility>
// #include <thread>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <cstdlib>

using namespace std;

void IsBigEndian()
{
    int a = 0x1122; //十六进制，一个数值占4位
    char b = *(char *)&a; //通过将short(2字节)强制类型转换成char单字节，b指向a的起始字节（低字节）
    if (b == 0x11)        //低字节存的是数据的高字节数据
    {
        //是大端模式
        cout << "Big" << endl;
    }
    else
    {
        //是小端模式
        cout << "Little" << endl;
    }
}

int main()
{
    IsBigEndian();
}

// template <typename T>
// int partition(T arr[], int left, int right)
// {
//     swap(arr[left + rand() % (right - left + 1)], arr[right]);

//     T pivot = arr[right];
//     int mark = left;
//     for (int i = left; i < right; i++)
//     {
//         if (arr[i] < pivot)
//             swap(arr[i], arr[mark++]);
//     }

//     swap(arr[mark], arr[right]);
//     return mark;
// }

// template <typename T>
// int partition2(T arr[], int left, int right)
// {
//     swap(arr[left + rand() % (right - left + 1)], arr[left]);

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

//         swap(arr[i++], arr[j--]);
//     }

//     swap(arr[j], arr[left]);
//     return j;
// }

// template <typename T>
// void __QuickSort(T arr[], int left, int right)
// {
//     if (left >= right)
//         return;

//     T pivot = partition2(arr, left, right);
//     __QuickSort(arr, left, pivot - 1);
//     __QuickSort(arr, pivot + 1, right);
// }

// template <typename T>
// void QuickSort(T arr[], int n)
// {
//     srand((unsigned int) time(nullptr));

//     __QuickSort(arr, 0, n - 1);
// }

// int main()
// {
//     // vector<float> arr = {9, 12, 4, 8, 10, 6, 7};
//     float arr[] = {9, 12, 4, 8, 10, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     QuickSort(arr, n);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;

//     return 0;
// }

// // 求根号下
// // 二分法
// double sqrt1(double x)
// {
//     double EPSILON = 0.00001;
//     double low = 0.0;
//     double high = x;
//     double mid = (low + high) / 2;
//     while ((high - low) > EPSILON)
//     {
//         if (mid > x / mid)
//         {
//             high = mid;
//         }
//         else
//         {
//             low = mid;
//         }
//         mid = (high + low) / 2;
//     }
//     return mid;
// }

// int main()
// {
//     double a = 99;
//     a = sqrt1(a);
//     cout << a << endl;
// }

// int main()
// {

//     int a[5] = {10, 12, 14, 6, 8};
//     priority_queue<int, vector<int>, less<int>> p;  //降序队列，大顶堆
//     priority_queue<int, vector<int>, greater<int>> q;  //升序队列，小顶堆

//     for (int i = 0; i < 5; i++)
//     {
//         p.push(a[i]);
//         q.push(a[i]);
//     }

//     cout << "less<int>:" << endl;
//     while (!p.empty())
//     {
//         cout << p.top() << " ";
//         p.pop();
//     }
//     cout << endl;

//     cout << "greater<int>:" << endl;
//     while (!q.empty())
//     {
//         cout << q.top() << " ";
//         q.pop();
//     }
//     cout << endl;
// }

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// int main()
// {
//     double a = 100001;
//     double b = 100000;
//     cout << double((a + b) / 2.0) << endl;
// }

// void GetMax(int *result, int *buf, int buflen)
// {
//     int i;
//     *result = *buf;
//     cout << result << endl;

//     for (i = 1; i < buflen; i++)
//     {
//         if (*result < buf[i])
//             *result = *(buf + i);
//         cout << result << endl;
//     }
// }

// int main()
// {
//     int buf[] = {3, 5, 4, 1, 2};
//     int max = 0;
//     cout << &max << endl;

//     GetMax(&max, buf, 5);

//     cout << &max << endl;
//     printf("final: %d\n", max);
//     return 0;
// }

// class Solution
// {
// public:
//     string compressString(string S)
//     {
//         string res = "";
//         int i = 0;
//         while (i < S.size())
//         {
//             int len = 0;
//             int j = i + 1;
//             while (j < S.size() && S[i] == S[j])
//                 j++;

//             len = j - i;

//             if (len < 4)
//             {
//                 while (j-- && j >= i)
//                     res += S[i];
//                 i += len;
//             }
//             else if (len > 55)
//             {
//                 res += "0Z";
//                 res += S[i];
//                 len -= 55;
//                 i += 55;
//             }
//             else  // 4 <= len <= 55
//             {
//                 res += "0";
//                 // int offset = len - 4;
//                 // char tmp = 'a' + offset;
//                 // res += tmp;
//                 res += 'a' + len - 3;
//                 res += S[i];
//                 i += len;
//             }
//         }

//         return res;
//     }
// };

// int main()
// {
//     string str = "abbbbbbAAAdcdddd";
//     // string str = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBeeeeeeeeeeFYHHnjHAPQQc";
//     // string str = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
//     // string str = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
//     // cout << str.size() << endl;

//     Solution s;
//     string res = s.compressString(str);
//     cout << res << endl;

//     return 0;
// }

// class Solution
// {
// public:
//     vector<int> GetNumVec(int N, string s)
//     {
//         vector<int> res;

//         int i = 0;
//         int sum = 0;
//         for (int i = 0; i < N; i++)
//             sum += s[i] - '0';

//         while (i <= s.size())
//         {
//         }
//     }

//     int a[5] = {1, 2, 3, 5, 8};
//     int b[5] = {13, 21, 34, 55, 89};
//     string s1 = "12358";
//     string s2 = "1321345589";
// };

// // 任意2-36进制数转换为10进制数
// int atoi_mine(string s, int radix)
// {
//     int res = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         char t = s[i];
//         if (t >= '0' && t <= '9')
//             res = res * radix + t - '0';
//         else
//             res = res * radix + t - 'A' + 10;
//     }

//     return res;
// }

// // 10进制数转换为任意的n进制数
// string itoa_mine(int num, int radix)
// {
//     string res = "";
//     // do
//     // {
//     //     int t = num % radix;
//     //     if (t >= 0 && t <= 9)
//     //         res += t + '0';
//     //     else
//     //        res += t - 10 + 'A';
//     //     num /= radix;

//     // } while (num != 0);

//     while (num != 0)
//     {
//         int t = num % radix;
//         if (t >= 0 && t <= 9)
//             res += t + '0';
//         else
//            res += t - 10 + 'A';
//         num /= radix;
//     }

//     reverse(res.begin(), res.end());
//     return res;
// }

// int main()
// {
//     string str = "16";
//     int res_int = atoi_mine(str, 8);
//     cout << res_int << endl;

//     int num = 123;
//     string res_str = itoa_mine(num, 36);
//     cout << res_str << endl;

//     return 0;
// }

// class Solution
// {
// public:
//     string itoa(int num)
//     {
//         string res = "";
//         while (num)
//         {
//             switch (num % 3)
//             {
//             case 0:
//                 // res += '@';
//                 res = '@' + res;
//                 break;
//             case 1:
//                 // res += '$';
//                 res = '$' + res;
//                 break;
//             case 2:
//                 // res += '&';
//                 res = '&' + res;
//                 break;
//             default:
//                 break;
//             }
//             num /= 3;
//         }
//         // reverse(res.begin(), res.end());
//         return res;
//     }
// };

// int main()
// {

//     // Solution s;
//     // // string res;
//     // // res = s.itoa(123);
//     // // res = s.itoa(23);
//     // char str[100];
//     // string res;
//     // res = itoa(123, str, 3);
//     // cout << res;

//     char cc[20] = "-100";
//     int dd;
//     dd = atoi(cc);
//     cout << dd;

//     return EXIT_SUCCESS;
// }

// int main()
// {

//     int a[5] = {10, 12, 14, 6, 8};
//     priority_queue<int, vector<int>, less<int>> p;
//     priority_queue<int, vector<int>, greater<int>> q;

//     for (int i = 0; i < 5; i++)
//     {
//         p.push(a[i]);
//         q.push(a[i]);
//     }

//     cout << "less<int>:" << endl;
//     while (!p.empty())
//     {
//         cout << p.top() << " ";
//         p.pop();
//     }
//     cout << endl;

//     cout << "greater<int>:" << endl;
//     while (!q.empty())
//     {
//         cout << q.top() << " ";
//         q.pop();
//     }
//     cout << endl;
// }

// int i = 0;
// struct node
// {
//     int val;
//     node(int a) : val(a) {}
//     friend bool operator<(node a, node b)
//     {
//         i++;
//         cout << i << " ";
//         cout << a.val << "--->" << b.val << endl;
//         return a.val > b.val;
//     }
// };

// int main()
// {
//     priority_queue<node> Q;
//     Q.push(node(1000));
//     Q.push(node(100));
//     Q.push(node(2));
//     Q.push(20);
//     Q.push(30);
//     cout << i << endl;;
//     cout << "-------------" << endl;
//     cout << Q.top().val;
//     return 0;
// }

// int i = 0;
// bool cmp(int a, int b)
// {
//     i++;
//     cout << i << " ";
//     cout << a << "--->" << b << endl;
//     return a < b;
// }

// int main()
// {
//     vector<int> vec = {1, 2, 3, 5, -1};
//     sort(vec.begin(), vec.end(), cmp);
//     cout << "--------------" << endl;
//     for (int e : vec)
//     {
//         cout << e;
//     }
//     cout << endl;
//     cout << i;
// }

// bool cmp(int a, int b)
// {
//     return a > b;
// }

// int main()
// {
//     int numbers[] = {20, 40, 50, 10, 30};
//     // std::sort(numbers, numbers + 5, less<int>());
//     std::sort(numbers, numbers + 5, cmp);
//     for (int i = 0; i < 5; i++)
//         std::cout << numbers[i] << ' ';
//     std::cout << '\n';
//     return 0;
// }

// int main()
// {
//     char str1[] = "abc";
//     char str2[] = "abc";
//     const char str3[] = "abc";
//     const char str4[] = "abc";
//     const char *str5 = "abc";
//     const char *str6 = "abc";
//     cout << str1 << " " << str2 << endl;

//     cout << boolalpha << (str1 == str2) << endl;
//     cout << boolalpha << (str3 == str4) << endl;
//     cout << boolalpha << (str5 == str6) << endl;
// }

// int main()
// {
//     int data = GetData(); // 0
//     int *ptr_data = &data;
//     cout << data << endl;
//     cout << "===========" << endl;

//     A a(data);
//     auto incr1 = [=]() { a._data++; };
//     auto incr2 = [=]() { a.Incr(); };
//     auto incr3 = [=]() { Incr(const_cast<int &>(data)); };
//     auto incr4 = [=]() { Incr(*ptr_data); };

//     incr1(); // 1
//     cout << data << endl;
//     incr2(); // 2
//     cout << data << endl;
//     incr3(); // 2
//     cout << data << endl;
//     incr4(); // 3
//     cout << data << endl;

//     printf("%d", data); // 3
// }

// int main()
// {
//     float a = 0;
//     while (true)
//     {
//         a++;
//     }
//     cout << a << endl;
//     return 0;
// }

// class KnapSack
// {
// public:
//     int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
//     {
//         assert(w.size() == v.size());
//         int n = w.size();

//         // vector<vector<int>> dp(n, )

//     }

// };

// class Knapsack01{

// private:
//     vector<vector<int>> memo;

//     // 用 [0...index]的物品,填充容积为c的背包的最大价值
//     int bestValue(const vector<int> &w, const vector<int> &v, int index, int c){

//         if(c <= 0 || index < 0)
//             return 0;

//         if(memo[index][c] != -1)
//             return memo[index][c];

//         int res = bestValue(w, v, index-1, c);
//         if(c >= w[index])
//             res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
//         memo[index][c] = res;
//         return res;
//     }

// public:
//     int knapsack01(const vector<int> &w, const vector<int> &v, int C){
//         assert(w.size() == v.size() && C >= 0);
//         int n = w.size();
//         if(n == 0 || C == 0)
//             return 0;

//         memo.clear();
//         for(int i = 0 ; i < n ; i ++)
//             memo.push_back(vector<int>(C + 1, -1));
//         return bestValue(w, v, n - 1, C);
//     }
// };

// class KnapSack
// {
// public:
//     int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
//     {
//         // memo是对index，C的状态的记忆化记录, C+1表示从0到C的容量
//         // memo = vector<vector<int>>(w.size(), vector<int>(C + 1, -1));

//         for (int i = 0; i < w.size(); i++)
//             memo.push_back(vector<int>(C + 1, -1));
//         return BestValue(w, v, w.size() - 1, C);
//     }

// private:
//     vector<vector<int>> memo;

//     int BestValue(const vector<int> &w, const vector<int> &v, int index, int C)
//     {
//         if (index < 0 || C <= 0)
//             return 0;

//         if (memo[index][C] != -1)
//             return memo[index][C];

//         int res = BestValue(w, v, index - 1, C);
//         if (C >= w[index])
//             res = max(res, v[index] + BestValue(w, v, index - 1, C - w[index]));

//         memo[index][C] = res;
//         return res;
//     }
// };

// int main()
// {
//     vector<int> weight = {1, 2, 3};
//     vector<int> value = {6, 10, 12};
//     int C = 5;

//     KnapSack k;
//     int res = k.KnapSack01(weight, value, 5);
//     cout << res << endl;
//     return 0;
// }

// int main()
// {
//     vector<int> weight, value;
//     int n, C;
//     cin >> n >> C;

//     int w, v;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> w >> v;
//         weight.push_back(w);
//         value.push_back(v);
//     }
//     cout << KnapSack().KnapSack01(weight, value, C) << endl;

//     return 0;
// }

// int main()
// {
//     stringstream outstr;
//     string hdisk;
//     getline(cin, hdisk);
//     // char hdisk[80];
//     // cin.getline(hdisk, 80);

//     int cap;
//     cin >> cap;
//     outstr << "The hard disk " << hdisk << " has a capacity of "
//            << cap << " gigabyters.\n";

//     string result = outstr.str();
//     cout << result;
//     return 0;
// }

// stringstream outstr;
// double price = 2.0;
// const char *ps = " for a copy of the ISO";
// outstr.precision(2);
// outstr << fixed;
// outstr << "Pay only CHF " << price << ps << endl;
// string msg = outstr.str();
// cout << msg << endl;

// return 0;

// int main(int argc, char *argv[])
// {
// if (argc == 1)
// {
//     cout << "Usage: " << argv[0] << " filename[s]" << endl;
//     exit(EXIT_FAILURE);
// }
// string str = "test1";
// char *s = nullptr;

// const char *constc = str.c_str();
// s = const_cast<char *>(constc);
// cout << s << endl;

// char ch;
// string file_name = "test.txt";
// // cout << file_name << " " << &file_name << " " << (char *)file_name.c_str() << endl;
// ifstream fin;
// fin.open(file_name);
// if (fin.is_open())
// {
//     while (fin.get(ch))
//         cout << ch;
//     fin.close();
// }

// fstream finout;
// finout.open(file_name, ios_base::out | ios_base::app);

// ifstream fin(file_name);
// // string output;
// // char buff[80] = {};
// // finout.getline(buff, 80);

// string buff;
// finout >> buff;
// // getline(finout, buff);
// cout << buff << endl;
// // finout >> output;
// }

// int main()
// {
//     char great_input[20] = {};
//     char ch;
//     int i = 0;
//     while ((ch = cin.peek()) != '.' && ch != EOF)
//     {
//         cin.get(great_input[i++]);
//     }
//     great_input[i] = '\0';
//     cout << great_input << endl;
//     // cin.getline(name, 19);
//     // cin.get(name, 19, ' ');
//     // cin.get(name, 19);
//     // cout << name << endl;
// }

// int main()
// {
//     int cnt = 0;
//     int ch;
//     while ((ch = cin.get()) != EOF)
//     {
//         cout << ch;
//     }

//     return 0;
// }

// int main()
// {
//     char ch;
//     int num = 0;
//     // cin.get(ch);
//     // cin >> ch;
//     while (cin.get(ch))
//     {
//         cout << ch;
//         num++;
//         // cin.get(ch);
//         // cin >> ch;
//     }
//     cout << endl;
//     cout << num << endl;
//     return 0;
// }

// int main()
// {
//     int input;
//     int sum;
//     int tmp;
//     while (cin >> input)
//     {
//         sum += input;
//     }
//     cin.clear();
//     if (cin.fail() && !cin.eof())
//     {
//         cin.clear();
//         while (!isspace(cin.get()))
//         {
//             continue;
//         }
//     }
//     else
//     {
//         exit(EXIT_FAILURE);
//     }

//     // while (!isspace(cin.get()))
//     // {
//     //     continue;
//     // }
//     // while (cin.get() != '\n')
//     // {
//     //     continue;
//     // }

//     cin >> tmp;
//     sum += tmp;
//     cout << "Sum = " << sum << endl;
//     return 0;
// }

// int main()
// {
//     int egg = 10;
//     const char *amount = "dozen";
//     cout << &egg << endl;
//     cout << &amount << endl;
//     cout << (void *)amount << endl;

//     cout.put('a');
//     cout.put('b');
//     cout << 'W' << endl;
//     cout.put('W');

//     long val = 560031841;
//     cout.write((char *)&val, sizeof(long));
//     cout << endl;

//     // ios_base::fmtflags old = cout.setf(ios_base::left, ios_base::adjustfield);
//     // cout.setf(old, ios_base::adjustfield);

//     cout << uppercase << noboolalpha;
//     cout << true << endl;
//     cout.unsetf(ios_base::boolalpha);
//     cout <<  (1 == 2) << endl;
//     cout.setf(ios_base::boolalpha);
//     cout <<  (1 == 2) << endl;

//     return 0;
// }

// int main()
// {

//     string line;
//     int a, b;

//     stringstream ss;
//     getline(cin, line);
//     ss << line;
//     ss >> a >> b;
//     cout << a << " " << b << endl;
//     // ss << line;
//     // while (getline(cin, line))
//     // {
//     //     // ss << line;
//     //     // ss >> a;
//     //     // cout << a << endl;
//     // }

//     // int a;
//     // ss >> a;

//     // cout << a << endl;
//     return 0;
// }

// int main()
// {
//     double a = 94911151;
//     double b = 94911150;
//     cout << a << endl;
//     cout << b << endl;
//     int a = 1;
//     int b = 1;
//     bool is_true = a == b ? true : false;
//     cout << is_true << endl;
//     cout << sizeof(float) << endl;
// }

// class Test
// {
// public:
//     Test()
//     {
//         cout << "调用 默认构造" << endl;
//     }

//     Test(int x) : a(x)
//     {
//         cout << "调用 有参构造" << endl;
//     }

//     Test(Test const &other) : a(other.a)
//     {
//         cout << "调用 拷贝构造" << endl;
//     }

//     ~Test()
//     {
//         cout << "调用 析构" << endl;
//     }

//     int a;
// };

// Test &func()
// {
//     Test *p = new Test(2);
//     cout << "func: " << (*p).a << " " << p << " " << &p << endl;
//     return *p;
// }

// // const Test operator*(Test m, Test n)
// // {
// //     return m.a * n.a;
// // }

// int main()
// {
//     // Test &tmp = func();
//     // cout << tmp.a << " " << &tmp << endl;
//     // cout << "===========" << endl;

//     // tmp.a = 10;
//     // cout << tmp.a << " " << &tmp << endl;
//     // cout << "===========" << endl;

//     // cout << (func().a = 3) << endl;

//     Test const & tmp = func();

//     // func().a = 1;
//     cout << func().a << endl;
//     return 0;
// }

// class Person
// {
// public:
//     Person() {}

//     Person(int age, int height)/*  : m_age(age), m_height(new int(height)) */
//     {
//         this->m_age = age;
//         this->m_height = new int(height);
//     }

//     Person(Person const &p)
//     {
//         this->m_age = p.m_age;
//         this->m_height = new int(*p.m_height);
//     }

//     ~Person()
//     {
//         if (m_height != nullptr)
//         {
//             delete m_height;
//             m_height = nullptr;
//         }
//     }

// private:
//     int m_age;
//     int *m_height;
// };

// struct MyComp
// {
//     bool operator()(int a, int b)
//     {
//         return a % 10 < b % 10;
//     }
// };

// // int main()
// // {
// //     vector<int> vec;
// //     for (int i = 0; i < 10; i++)
// //     {
// //         int num = rand() % 100;
// //         vec.push_back(num);
// //         cout << "insert " << num << " in vector." << endl;
// //     }
// //     for (auto &e : vec)
// //     {
// //         cout << e << " ";
// //     }
// // }

// int main()
// {
//     priority_queue<int, vector<int>, less<int>> pq;
//     for (int i = 0; i < 10; i++)
//     {
//         int num = rand() % 100;
//         pq.push(num);
//         cout << "insert " << num << " in priority queue." << endl;
//     }
//     while (!pq.empty())
//     {
//         cout << pq.top() << " ";
//         pq.pop();
//     }
//     // cout << endl;
//     return 0;
// }

// int main()
// {
//     vector<int> vec(12, 0);
//     for (int i = 0; i < 12; i++)
//     {
//         vec[i] = i;
//     }

//     for (auto &e : vec)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
//     cout << "=======" << endl;

//     cout << vec.size() << " " <<  vec.capacity() << endl;
//     vec.erase(vec.begin());
//     // vec.erase(vec.begin());
//     cout << vec.size() << " " << vec.capacity() << endl;
//     cout << "=======" << endl;

//     vec.push_back(1);
//     // vec.push_back(2);
//     cout << vec.size() << " " <<  vec.capacity() << endl;

//     for (auto &e : vec)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
//     vec.erase(vec.begin());
//     cout << vec.size() << " " <<  vec.capacity() << endl;

// }

// int main()
// {
//     int test = 6;
//     cout << &test << endl;
//     int *a = new int(3);
//     int *b = a;
//     cout << "a: " << *a << " " << a << " " << &a << endl;
//     cout << "b: " << *b << " " << b << " " << &b << endl;

//     delete a;
//     cout << "a: " << *a << " " << a << " " << &a << endl;
//     cout << "b: " << *b << " " << b << " " << &b << endl;

//     a = &test;
//     cout << "a: " << *a << " " << a << " " << &a << endl;
//     cout << "b: " << *b << " " << b << " " << &b << endl;
// }

// int num;
// vector<int> memo;

// int fib(int n)
// {
//     num++;
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return 1;

//     if (memo[n] == -1)
//         memo[n] = fib(n - 1) + fib(n - 2);
//     return memo[n];
// }

// int fib_origin(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return 1;
//     return fib(n - 1) + fib(n - 2);
// }

// int fib_better(int n)
// {
//     num++;
//     vector<int> memo(n + 1, -1);

//     memo[0] = 0;
//     memo[1] = 1;

//     for (int i = 2; i <= n; ++i)
//         memo[i] = memo[i - 1] + memo[i - 2];

//     return memo[n];
// }

// int main()
// {
//     num = 0;

//     int n = 45;
//     memo = vector<int> (n + 1, -1);

//     time_t start = clock();
//     int res = fib(n);
//     time_t end = clock();
//     cout << res << " " << num << endl;
//     cout << "time used: " << double(end - start) / 1000 << endl;
// }

// struct MyHash
// {
//     size_t operator()(const pair<int, int> &x) const
//     {
//         return hash<size_t>()(hash<int>()(x.first)) ^ hash<int>()(x.second);
//     }
// };

// int main()
// {
//     vector<pair<int, int>> vec;
//     vec.push_back(pair<int, int>(2, 5));

//     unordered_map<pair<int, int>, int, MyHash> record;

//     record[pair<int, int> (0, 0)];
//     for (auto const &e : record)
//     {
//         cout << e.first.first << " " << e.first.second << " " << e.second << endl;
//     }
//     // string test = "test";
//     // cout << hash<string>()(test) << endl;

//     // cout << vec[0].first << " " << hash<int>()(vec[0].first) << endl;
//     // cout << vec[0].second << " " << hash<int>()(vec[0].second) << endl;
//     // cout << (hash<size_t>()(hash<int>()(vec[0].first)) ^ hash<int>()(vec[0].second)) << endl;

//     return 0;
// }

// int main()
// {
//     unordered_multimap<int, int> record;
//     record.insert(make_pair(1, 10));
//     record.insert(make_pair(2, 5));
//     record.insert(make_pair(2, 20));
//     record.insert(make_pair(2, 50));
//     record.insert(make_pair(3, 30));

//     // auto iter = record.find(2);
//     // if (iter != end(record))
//     // {
//     //     cout << iter->first << " " << iter->second << endl;
//     // }

//     // cout << "============" << endl;

//     auto it = record.equal_range(2);

//     // cout << it.first->second << it.second->second << endl;
//     // cout << "============" << endl;

//     if (it.first != record.end()) // it.first，it.second分别指向该key值对应的value值的起始和终止位置
//     {
//         for (auto p = it.first; p != it.second; p++)
//         {
//             cout << p->first << " " << p->second << endl;
//         }
//     }

//     return 0;
// }

// struct ListNode
// {
//     float val;
//     ListNode *next;
//     ListNode(float x) : val(x), next(nullptr) {}
// };

// // 展示已经构建的链表
// void DisplayLists(ListNode *node)
// {
//     cout << "您当前的链表结构如下所示: " << endl;

//     if (node)
//     {
//         cout << node->val;
//         node = node->next;
//     }
//     while (node)
//     {
//         cout << " -> " << node->val;
//         node = node->next;
//     }
//     cout << endl;
// }

// // 删除链表中指定的第index个节点, 从0开始索引
// void DeleteListNode(ListNode &node)
// {

//     cout << "请输入要删除链表节点的序号(从0开始索引): " << endl;
//     int index;
//     cin >> index;

//     ListNode *ptr = &node;
//     for (int i = 0; i <= index && ptr != nullptr && ptr->next != nullptr; i++)
//     {
//         if (i == index)
//         {
//             // 删除指定链表节点
//             ListNode *bak = ptr->next;
//             ptr->next = ptr->next->next;
//             delete bak;
//             return;
//         }
//         else
//         {
//             ptr = ptr->next;
//         }
//     }
// }

// // 在程序结束时释放链表在堆区的内存
// void FreeLists(ListNode *node)
// {
//     ListNode *prev = node;
//     while (node)
//     {
//         prev = prev->next;
//         delete node;
//         node = prev;
//     }
// }

// int main()
// {
//     // 使用尾部插入法建立具有5个节点的单向链表，
//     // 要求能够按照给定数值删除指定节点

//     cout << "请输入要构建链表的节点数: " << endl;
//     int N;
//     cin >> N;

//     ListNode dummy(-1); // 虚拟链表头
//     ListNode *ptr_tmp = &dummy;
//     for (int i = 0; i < N; i++)
//     {
//         cout << "请输入第" << i << "个节点的值: ";
//         float val;
//         cin >> val; // 输入每个链表节点的value

//         ListNode *tmp = new ListNode(val);
//         ptr_tmp->next = tmp;
//         ptr_tmp = ptr_tmp->next;
//     }

//     DisplayLists(dummy.next);
//     DeleteListNode(dummy);
//     DisplayLists(dummy.next);

//     FreeLists(dummy.next); // new出的节点在堆区，需要手动释放
//     return 0;
// }

// int main()
// {
//     char str[100];
//     int offset = 0;
//     // srand(time(0));
//     // srand((unsigned int)time(nullptr));
//     for (int i = 0; i < 100; i++)
//     {
//         offset += sprintf(str + offset, "%d,", rand() % 100);
//     }
//     str[offset - 1] = '\n';
//     printf(str);
//     return 0;
// }

// int seq1[] = {1, 2, 3, 3, 4, 5}, seq2[] = {9, 8, 7, 7, 6, 5};

// int main()
// {

//     set<int> record;
//     //cout<<upper_bound(seq1, seq1+6, 3, greater<int>()) - seq1<<endl;
//     //cout<<lower_bound(seq1, seq1+6, 3, greater<int>()) - seq1<<endl;
//     cout << upper_bound(seq1, seq1 + 6, 3) - seq1 << endl;
//     cout << lower_bound(seq1, seq1 + 6, 3) - seq1 << endl;

//     cout << endl;

//     cout << upper_bound(seq2, seq2 + 6, 7, greater<int>()) - seq2 << endl;
//     cout << lower_bound(seq2, seq2 + 6, 7, greater<int>()) - seq2 << endl;
//     //cout<<upper_bound(seq2, seq2+6, 7) - seq2<<endl;
//     //cout<<lower_bound(seq2, seq2+6, 7) - seq2<<endl;
//     return 0;
// }

// static const auto ______ = [] (int x) {
//     cout << "lambda表达式" << endl;
//     cout << x << endl;

//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return 0;
// };

// int main()
// {
//     cout << "main" << endl;
//     ______(333);
//     return 0;
// }

// bool isPalindrome(string s)
// {
//     string str;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (isalnum(s[i]))
//         {
//             str += tolower(s[i]);
//         }
//     }

//     string str_cmp(str);
//     cout << "str: " << str << endl;

//     str_cmp.reserve();
//     cout << "str_cmp: " << str_cmp << endl;

//     if (str_cmp == str)
//     {
//         return true;
//     }
//     return false;
// }

// void Exchange(string s, int left, int right)
// {
//     char tmp;
//     tmp = s[left];
//     s[left] = s[right];
//     s[right] = tmp;
// }

// int main()
// {
//     // string str = "race a car";
//     string str = "race";
//     // cout << isPalindrome(str) << endl;
//     cout << str << endl;

//     // Exchange(str, 1, 3);
//     swap(str[1], str[3]);
//     cout << str << endl;

//     // string str_cmp(str);
//     // str_cmp.assign(str.rend(), str.rbegin());
//     // reverse(str_cmp.begin(), str_cmp.end());
//     // cout << str_cmp << endl;

//     // cout << "str.size(): " << str.size() << endl;

//     // string cmp(str.rend(), str.rbegin());
//     // cout << cmp << endl;
//     // cout << "cmp.size(): " << cmp.size() << endl;

//     return 0;
// }

// int main()
// {
//     // int *ptr = (int *)malloc(5 * sizeof(int));
//     // free(ptr);

//     vector<int> nums{1, 2, 3, 4, 5};
//     cout << nums.size() << endl;
//     cout << nums.capacity() << endl;
//     nums.erase(nums.begin() + 2);
//     cout << nums[2] << endl;
//     for (auto e : nums)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
//     cout << nums.size() << endl;
//     cout << nums.capacity() << endl;

//     return 0;
// }

// class background_task
// {
// public:
//     void operator()() const
//     {
//         // do_something();
//         // do_something_else();
//     }
// };

// bool f3(int x)
// {
//     return x % 3 == 0;
// }

// class f_mod
// {
// private:
//     int dv;

// public:
//     f_mod(int x = 1) : dv(x) {}
//     bool operator()(int x)
//     {
//         return x % dv == 0;
//     }
// };

// int main()
// {
//     const long SIZE = 36L;
//     vector<int> nums(SIZE);
//     srand((unsigned int)time(nullptr));
//     generate(nums.begin(), nums.end(), rand);

//     auto mod3 = [](int x) { return x % 3 == 0; };

//     int cnt = count_if(nums.begin(), nums.end(), f3);
//     int cnt2 = count_if(nums.begin(), nums.end(), f_mod(3));
//     int cnt3 = count_if(nums.begin(), nums.end(), [](int x) { return x % 3 == 0; });

//     int cnt_3 = 0;
//     int cnt_13 = 0;
//     for_each(nums.begin(), nums.end(), [&](int x) { cnt_3 += x % 3 == 0; cnt_13 += x % 13 == 0; });

//     cout << cnt_3 << endl;
//     cout << cnt_13 << endl;

//     // for (auto e : nums)
//     // {
//     //     cout << e << endl;
//     // }
// }

// int main()
// {
//     std::string str = "Hello";
//     std::vector<std::string> v;
//     //调用常规的拷贝构造函数，新建字符数组，拷贝数据
//     v.push_back(str);
//     std::cout << "After copy, str is \"" << str << "\"\n";
//     //调用移动构造函数，掏空str，掏空后，最好不要使用str
//     v.push_back(std::move(str));
//     std::cout << "After move, str is \"" << str << "\"\n";
//     std::cout << "The contents of the vector are \"" << v[0]
//                                          << "\", \"" << v[1] << "\"\n";
// }

// int main()
// {
//     int a = 2;
//     cout << "a: " << &a << a << endl;

//     int b = move(a);

//     cout << "a: " << &a << a << " b: " << &b << b << endl;
//     return 0;
// }

// vector<vector<int>> v1;

// typedef vector<int>::iterator ItType;
// using ItType = vector<int>::iterator;

// template <typename T>
// using arr12 = array<T, 12>;

// array<double, 12> a1;
// array<string, 12> a2;

// arr12<double> a1;
// arr12<string> a2;

// int i = 0;
// decltype(i) j;

// template <typename T, typename U>
// auto func(T t, U u) -> decltype(t * u)
// {
// }

// template <typename _Tx, typename _Ty>
// auto multiply(_Tx x, _Ty y)->decltype(_Tx*_Ty)
// {
//     return x*y;
// }

// auto sum(initializer_list<double> list) -> double
// {
//     return 0;
// }

// int main()
// {
//     int b = sum({1, 2, 3, 4});

//     return 0;
// }

// int main()
// {
//     string lit = "It was a dark and stormy day.";
//     string str = "1 2 3 4 5 6 7 8 9";
//     istringstream instr(lit);

//     int n;
//     // int sum = 0;
//     // while (instr >> n)
//     // {
//     //     sum += n;
//     // }
//     // cout << "sum: " << sum << endl;

//     string word;
//     while (instr >> word)
//     {
//         cout << word << endl;
//     }
//     return 0;
// }

// int main()
// {
//     cout << "This system can generate up to " << TMP_MAX
//          << " temporary names of up to " << L_tmpnam
//          << " characters.\n";
//     char psz_name[L_tmpnam] = {'\0'};
//     cout << "Here are ten names:\n";
//     for (int i = 0; i < 3; i++)
//     {
//         tmpnam(psz_name);
//         cout << psz_name << endl;
//     }
//     return 0;
// }

// inline void EatLine() { while (cin.get() != '\n') continue; }
// static const int NAME_LEN = 20;

// struct Planet
// {
//     char name[NAME_LEN];
//     double population;
//     double g; // gravity
// };

// int main()
// {
//     // 显示当前内容
//     Planet pl;
//     string file_name;
//     fstream finout;
//     finout.open(file_name, ios_base::in | ios_base::out | ios_base::binary);
//     int cnt = 0;
//     if (finout.is_open())
//     {
//         finout.seekg(0);
//         while (finout.read((char *) &pl, sizeof(pl)))
//         {
//             cout << cnt++ << ": " << setw(NAME_LEN) << pl.name << ": "
//                  << setprecision(0) << setw(12) << pl.population
//                  << setprecision(2) << setw(6) << pl.g << endl;
//         }
//         if (finout.eof())
//         {
//             finout.clear();
//         }
//         else
//         {
//             cerr << "Error in reading " << file_name << " file\n";
//             exit(EXIT_FAILURE);
//         }
//         finout.close();
//     }
//     else
//     {
//         cerr << file_name << " could not be opened -- bye.\n";
//         exit(EXIT_FAILURE);
//     }

//     // 询问修改的是哪条内容
//     long rec;
//     cin >> rec;
//     EatLine();
//     if (rec < 0 || rec >= cnt)
//     {
//         cerr << "Invalid record number -- bye.\n";
//         exit(EXIT_FAILURE);
//     }
//     streampos place = rec * sizeof(pl);
//     finout.seekg(place);

//     finout.read((char *) &pl, sizeof(pl));
//     cout << "Your selection: \n";
//     cout << rec << ": " << setw(NAME_LEN) << pl.name << ": "
//          << setprecision(0) << setw(12) << pl.population
//          << setprecision(2) << setw(6) << pl.g << endl;

//     if (finout.eof())
//         finout.clear();

//     // 修改内容
//     cout << "Enter your name: " ;
//     cin.get(pl.name, NAME_LEN);
//     EatLine();
//     cout << "Enter planetary population: ";
//     cin >> pl.population;
//     cout << "Enter planetary gravity: ";
//     cin >> pl.g;
//     finout.seekg(place);
//     finout.write((char *) &pl, sizeof(pl)) << flush;
//     if (finout.fail())
//     {
//         cerr << "Error on attempted write\n";
//         exit(EXIT_FAILURE);
//     }

//     // 显示修改后的文件
//     cnt = 0;
//     finout.seekg(0);
//     while (finout.read((char *) &pl, sizeof(pl)))
//     {
//         cout << cnt++ << ": " << setw(NAME_LEN) << pl.name << ": "
//              << setprecision(0) << setw(12) << pl.population
//              << setprecision(2) << setw(6) << pl.g << endl;
//     }
//     finout.close();
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     // const char *file_name = "test.txt";
//     ios_base::seekdir;
//     if (argc == 1)
//     {
//         cerr << "Usage " << argv[0] << "filename[s]" << endl;
//         exit(EXIT_FAILURE);
//     }
//     const char *file_name = argv[1];

//     Planet pl;
//     cout << fixed << right;

//     // show initial contents
//     ifstream fin;
//     fin.open(file_name, ios_base::in | ios_base::binary);
//     if (fin.is_open())
//     {
//         cout << "Here are the current: " << file_name << " file\n";
//     }
//     while (fin.read((char *) &pl, sizeof(pl)))
//     {
//         cout << setw(NAME_LEN) << pl.name << ": "
//              << setprecision(0) << setw(12) << pl.population
//              << setprecision(2) << setw(6) << pl.g << endl;
//     }
//     fin.close();

//     // add new data
//     ofstream fout(file_name, ios_base::out | ios_base::app | ios_base::binary);
//     if (!fout.is_open())
//     {
//         cerr << "Can't open " << file_name << " file for output:\n";
//         exit(EXIT_FAILURE);
//     }

//     cout << "Enter planet name: \n";
//     cin.get(pl.name, NAME_LEN);
//     while (pl.name[0] != '\0')
//     {
//         EatLine();
//         cout << "Enter planetary population:";
//         cin >> pl.g;
//         cout << "Enter planetary g:";
//         cin >> pl.g;
//         EatLine();
//         fout.write((char *) &pl, sizeof(pl));
//         cout << "Enter planet name: \n";
//         cin.get(pl.name, NAME_LEN);
//     }
//     fout.close();

//     // show revised file
//     fin.clear();
//     fin.open(file_name, ios_base::in | ios_base::binary);
//     if (fin.is_open())
//     {
//         cout << "Here are the new contents of the " << file_name << " file:\n";
//         while (fin.read((char *) &pl, sizeof(pl)))
//         {
//             cout << setw(NAME_LEN) << pl.name << ": "
//                  << setprecision(0) << setw(12) << pl.population
//                  << setprecision(2) << setw(6) << pl.g << endl;
//         }
//         fin.close();
//     }

//     cout << "Done.\n";
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     // if (argc == 1)
//     // {
//     //     cerr << "Usage: " << argv[0] << "filename[s]" << endl;
//     //     exit(EXIT_FAILURE);
//     // }

//     string file_name = "./selftest/test.txt";
//     char ch;
//     ifstream fin;
//     fin.open(file_name);
//     if (fin.is_open())
//     {
//         cout << "Here are the current contents: " << file_name << " file:\n";
//         while (fin.get(ch))
//         {
//             cout << ch;
//         }
//         fin.close();
//     }

//     // Add new names
//     ofstream fout(file_name, ios::out | ios::app);
//     if (!fout.is_open())
//     {
//         cerr << "Open failed: " << file_name << " file" << endl;
//         exit(EXIT_FAILURE);
//     }
//     cout << "Enter guest names." << endl;
//     string name;
//     while (getline(cin, name) && name.size() > 0)
//     {
//         fout << name << endl;
//     }
//     fout.close();

//     // Show revised file
//     fin.clear();
//     fin.open(file_name);
//     if (fin.is_open())
//     {
//         cout << "Here are the new contents: " << file_name << " file\n";
//         while (fin.get(ch))
//         {
//             cout << ch;
//         }
//         fin.close();
//     }
//     cout << "Done" << endl;
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     if (argc == 1)
//     {
//         cerr << "Usage: " << argv[0] << " filename[s]" << endl;
//         exit(EXIT_FAILURE);
//     }

//     ifstream fin;
//     long count;
//     long total = 0;
//     char ch;
//     for (int file = 1; file < argc; file++)
//     {
//         fin.open(argv[file]);
//         if (!fin.is_open())
//         {
//             cerr << "Could not open " << argv[file] << endl;
//             // exit(EXIT_FAILURE);
//             fin.clear();
//             continue;
//         }

//         count = 0;
//         while (fin.get(ch))
//         {
//             count++;
//         }
//         cout << count << " characters in " << argv[file] << endl;
//         total += count;
//         fin.clear();
//         fin.close();
//     }
//     cout << total << " characters in all files\n";

//     // ifstream fin;
//     // fin.open(argv[file]);
//     // if (!fin.is_open()) // if (fin.fail())  // if (!fin)
//     // {
//     //     cerr << "Failed open" << endl;
//     // }

//     return 0;
// }

// int main()
// {
//     ifstream fin;
//     ofstream fout;
//     ofstream out_file;
//     out_file << "Hello" << endl;
//     string line;
//     getline(fin, line);

//     char ch;
//     unsigned char unch;
//     signed char sich;
//     ch = cin.get();
//     cin.get(ch);

//     int egg = 12;
//     const char *name = "kansas";
//     const char *name2 = "Xiaohong";
//     // cout << &egg << endl;
//     // cout << (void *)&egg << endl;
//     cout << name << endl;
//     cout << (void *)name << endl;
//     // cout.operator<<(name) << endl;
//     cout << endl;
//     cout.put('W')/* .put('I') */ << endl;

//     // cout.write(name, 20) << endl;

//     long val = 560031841;
//     cout.write((char *)&val, sizeof(val)) << endl;

//     double f = 1.2000;
//     cout << f << ":" << endl;
//     printf("%g", f);

//     cout << endl;
//     cout << dec;
//     cout << 67 << endl;
//     cout << hex;
//     cout << 67 << endl;
//     cout << oct;
//     cout << 67 << endl;

//     cout << '#';
//     cout.width(5);
//     cout << 12 << '#' << 24 << endl;

//     ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
//     // cout.setf(0, ios_base::floatfield);
//     cout.unsetf(ios_base::fixed);
//     cout.unsetf(ios_base::floatfield);

//     cout << noshowbase << endl;
//     cout << scientific << endl;

//     cin.operator>>(f);
//     char ch;
//     string str;
//     cin.get(ch).get();

//     int ch;
//     while ((ch = cin.get()) != EOF)
//     {
//         ch = cin.get();
//     }

//     char line[50];
//     cin.get(line, 50, ',');

//     char great_input[80];
//     char ch;
//     int i = 0;
//     while (ch = cin.peek() != '.' && ch != '\n')
//     {
//         cin.get(great_input[i++]);
//     }
//     great_input[i] = '\0';
// }

// template <typename T>
// class MyVector
// {
// private:
//     T *data;
//     int capacity;
//     int size;

//     // 复杂度O(n)
//     void resize(int new_capacity)
//     {
//         assert(new_capacity >= size);
//         T *new_data = new T[new_capacity];

//         for (int i = 0; i < size; i++)
//         {
//             new_data[i] = this->data[i];
//         }

//         delete[] this->data;
//         this->data = new_data;
//         this->capacity = new_capacity;
//     }

// public:
//     MyVector() : capacity(10), size(0)
//     {
//         data = new T[10];
//     }

//     ~MyVector()
//     {
//         delete[] data;
//     }

//     // 即使调用了O(n)复杂度的resize()方法，push_back()方法仍然是O(1)复杂度
//     void push_back(T e)
//     {
//         // assert(size < capacity);
//         if (size == capacity);
//             resize(capacity << 1);
//         data[size++] = e;
//     }

//     T pop_back()
//     {
//         assert(size > 0);
//         T ret = data[size - 1];
//         if (size == capacity / 2)
//             resize(capacity / 2);
//         return ret;
//     }
// };

// int main()
// {
//     for (int x = 1; x <= 10; x++)
//     {
//         int n = pow(10, x);

//         int sum = 0;
//         clock_t start_time = clock();

//         for (int i = 0; i < n; i++)
//             sum += i;

//         clock_t end_time = clock();

//         cout << "10^" << x << " :" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int a = 6;
//     int b = 5;
//     int *a_ptr = &a;

//     cout << "a的地址：" << &a << endl;
//     cout << "a_ptr指向的地址：" << a_ptr << endl;
//     cout << "a_ptr的值：" << *a_ptr << endl;
//     cout << "a_ptr的地址：" << &a_ptr << endl;
//     cout << endl;

//     int *b_ptr = a_ptr;
//     cout << "b_ptr指向的地址：" << b_ptr << endl;
//     cout << "b_ptr的值：" << *b_ptr << endl;
//     cout << "b_ptr的地址：" << &b_ptr << endl;
//     cout << endl;

//     // *a_ptr += 1;
//     a_ptr = &b;
//     cout << "a_ptr指向的地址：" << a_ptr << endl;
//     cout << "a_ptr的值：" << *a_ptr << endl;
//     cout << "a_ptr的地址：" << &a_ptr << endl;
//     cout << endl;

//     cout << "b_ptr指向的地址：" << b_ptr << endl;
//     cout << "b_ptr的值：" << *b_ptr << endl;
//     cout << "b_ptr的地址：" << &b_ptr << endl;
//     cout << endl;

//     return 0;
// }

// int partition(vector<int> &nums, int left, int right)
// {
//     swap(nums, randRange(left, right), right);
//     // 随机选择一个数作为基准值，nums[hi] 就是基准值 int i, j; for (i = left,
//     j = left; j < right; ++j)
//     {
//         if (nums[j] <= nums[right])
//             swap(nums, i++, j);
//     }
//     swap(nums, i, j);
//     return i;
// }

// int partition2(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[left]; // 取基准值
//     int mark = left;        // mark初始化为起始下标
//     for (int i = left + 1; i <= right; ++i)
//     {
//         if (nums[i] < pivot)
//         {
//             // 小于基准值则mark+1， 并交换位置
//             mark++;
//             swap(nums[mark], nums[i]);
//         }
//     }
//     // 基准值与mark对应元素调换位置
//     swap(nums[left], nums[mark]);
//     return mark;
// }

// int partition3(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[left]; // 将left作为基准
//     while (left < right)
//     {
//         while (left < right && nums[right] >= pivot)
//             right--;
//         nums[left] = nums[right];
//         while (left < right && nums[left] < pivot)
//             left++;
//         nums[right] = nums[left];
//     }
//     nums[left] = pivot;
//     return left;
// }

// void QuickSort(vector<int> &nums, int left, int right)
// {
//     if (left >= right)
//         return;
//     int pivot_idx = partition3(nums, left, right);
//     QuickSort(nums, left, pivot_idx - 1);
//     QuickSort(nums, pivot_idx + 1, right);
// }

// int main()
// {
//     vector<int> nums = {2, 1, 7, 9, 5, 8};
//     vector<int> nums2 = {9, 8, 7, 1, 5, 3};
//     vector<int> nums3 = {1, 2, 3, 7, 8, 9};
//     vector<int> nums4 = {5, 2, 7, 8, 3, 0, 6, 4};

//     // sort(nums.begin(), nums.end()))
//     for (auto i : nums4)
//     {
//         cout << i << ' ';
//     }
//     cout << endl;
//     cout << "============" << endl;
//     // select_sort(nums, 3);
//     QuickSort(nums4, 0, nums.size() - 1);
//     // ShellSort(nums2);
//     cout << "============" << endl;
//     for (auto i : nums4)
//     {
//         cout << i << ' ';
//     }
//     cout << endl;
//     return 0;
// }

// void test1()
// {
//     vector<int> v1 = {1, 2, 3};
//     vector<int> v2 = {4, 5, 6, 7, 8, 9};
//     auto it1 = v1.begin();
//     auto it2 = v2.begin();
//     cout << "交换前迭代器it1指向的元素为：" << *it1 << endl;
//     cout << "交换前迭代器it2指向的元素为：" << *it2 << endl;
//     cout << "交换前v1每个元素的地址和值为：";
//     for (const auto &it : v1)
//     {
//         cout << &it << " " << it << " ";
//     }
//     cout << "\n交换前v2每个元素的地址和值为：";
//     for (const auto &it : v2)
//     {
//         cout << &it << " " << it << " ";
//     }
//     swap(v1, v2);
//     cout << endl
//          << endl;
//     cout << "交换后迭代器it1指向的元素为：" << *it1 << endl;
//     cout << "交换后迭代器it2指向的元素为：" << *it2 << endl;
//     cout << endl;
//     auto it3 = v1.begin();
//     auto it4 = v2.begin();
//     cout << "交换后迭代器it3指向的元素为：" << *it3 << endl;
//     cout << "交换后迭代器it4指向的元素为：" << *it4 << endl;
//     cout << "交换后v1每个元素的地址和值为：";
//     for (const auto &it : v1)
//     {
//         cout << &it << " " << it << " ";
//     }
//     cout << "\n交换后v2每个元素的地址和值为：";
//     for (const auto &it : v2)
//     {
//         cout << &it << " " << it << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int a = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         a++;
//         cout<<a <<endl;
//     }
//     cout << "======" <<endl;
//     cout << a << endl;
//     vector<vector<int>> graph;
//     graph = vector<vector<int>>(a);
//     printf(graph.size());
//     return 0;
// }

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr){};
// };

// void add_to_vector(ListNode *head, vector<int> &vec)
// {
//     if (!head)
//     {
//         return;
//     }
//     vec.push_back(head->val);
//     add_to_vector(head->next, vec);
// }

// int main()
// {
//     const int RMB[] = {200, 100, 20, 10, 5, 1};
//     const int NUM = 6;
//     int x = 628;
//     int count = 0;
//     for (int i = 0; i < NUM; i++)
//     {
//         int use = X / RMB[i];
//         count += use;
//         x = x - RMB[i] * use;
//         cout << "需要面额为" << RMB[i] << "的有" << use << "张" << endl;
//         cout << "剩余需要支付的金额为" << x << endl;
//     }
//     cout << "总共需要" << count << "张" << endl;
//     return 0;
// }

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr){};
// };

// class Solution
// {
// private:
//     /* data */
// public:
//     ListNode *reverseList(ListNode *head);
// };

// ListNode *Solution::reverseList(ListNode *head)
// {
//     ListNode *new_head = nullptr;
//     ListNode *next_bak = nullptr;
//     while (head)
//     {
//         // 1.备份head->next
//         next_bak = head->next;
//         // 2.调整head指针
//         head->next = new_head;
//         // 3.调整new_head指针
//         new_head = head;
//         // 4.迭代head指针
//         head = next_bak;
//     }
//     return new_head;
// }

// int main()
// {
//     int a = 10;

//     cout << "你好Hello World!" << endl;

//     int b = 20;
//     cout << "b: " << b << endl;
//     cout << "中文" << b << endl;

//     system("pause");

//     return 0;
// }
