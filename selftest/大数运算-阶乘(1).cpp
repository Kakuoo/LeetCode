#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

/**
 * 大数运算 阶乘
 * 对于给定的整数n，计算n!
 * 数据规模：n的位数N（0 <= N <= 1000）
 * 
 * 使用字符数组实现阶乘
 */


// 1.使用字符串存储
// 1.1字符串存储初级版 暴力递归

string mutiple(string num1, int num2)
{
    string res;
    int up = 0; // 进位
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        int tmp = (num1[i] - '0') * num2 + up;
        up = tmp / 10;
        tmp = tmp % 10;
        res.insert(res.begin(), tmp + '0'); // 插入当前计算结果
    }
    while (up) // 插入剩余进位
    {
        int tmp = up % 10;
        up = up / 10;
        res.insert(res.begin(), tmp + '0');
    }
    return res;
}

string fac(int n) // 递归函数
{
    if (n == 0 || n == 1)
        return "1";
    else
        return mutiple(fac(n - 1), n);
}

int main()
{
    auto start_time = clock();
    int n;
    while (cin >> n)
    {
        cout << fac(n) << endl;
    }
    cout << "Time used: " << (double(clock() - start_time) / CLOCKS_PER_SEC) << endl;
    return 0;
}

// 1.使用字符串存储
// 1.2字符串存储初级版 提前制表，进行查询
// 但是依然没有达到指定精度，使用字符串存储大数会花费很多时间在类型转换上，这些过程十分的耗时

// vector<string> nVec(2, "1");
// string Mutiple(string num1, int num2) {...}

// string Fac(int x) //递归函数
// {
//     if (x >= nVec.size())
//     {
//         nVec.push_back(Mutiple(Fac(x - 1), x));
//     }
//     return nVec[x];
// }
// int main()
// {
//     ...
// }

// 2.使用数组存储
// 2.1 数组存储初级版

// vector<vector<int>> vec(2, vector<int>(1, 1));

// void mutiple(vector<int> num1, int num2)
// {
//     vector<int> res;
//     int up = 0;
//     for (auto it = num1.begin(); it != num1.end(); ++it)
//     {
//         int tmp = *it * num2 + up;
//         up = tmp / 10;
//         tmp = tmp % 10;
//         res.push_back(tmp);
//     }
//     while (up)
//     {
//         res.push_back(up % 10);
//         up = up / 10;
//     }
//     vec.push_back(res);
// }

// void cout_vec(vector<int> nums)
// {
//     for (int i = nums.size() - 1; i >= 0; --i)
//     {
//         cout << nums[i];
//     }
//     cout << endl;
// }

// vector<int> fac(int n)
// {
//     while (n >= vec.size())
//     {
//         mutiple(vec.back(), vec.size());
//     }
//     return vec[n];
// }

// int main()
// {
//     auto start_time = clock();
//     int n;
//     while (cin >> n)
//     {
//         cout_vec(fac(n));
//     }
//     cout << "Time used: " << double(clock() - start_time) / CLOCKS_PER_SEC << endl;
//     return 0;
// }


// 2.2 数组存储升级版
// 初级版终于满足了运行时间的要求，但是运行内存不达标。观察发现，并不需要将计算的所有结果都进行存储，只需要保留最后的计算结果就可以了。
// vector<int> nVec(1,1);
// int lastN = 1;
// void Mutiple(vector<int> num1, int num2)
// {
//     vector<int> res;
//     int c = 0;
// 	for (auto i = num1.begin(); i != num1.end(); i++){
//         int tmp = *i * num2 + c;
//         c = tmp / 10;
//         tmp = tmp % 10;
//         res.push_back(tmp);
//     }
//     while (c){
//         res.push_back(c % 10);
// 		c /= 10;
//     }
// 	nVec = res;
// }
// void CoutVec(vector<int> numPlus)
// {
// 	for(int i = numPlus.size() - 1; i >= 0; i--)
// 	{
// 		cout<<numPlus[i];
// 	}cout<<::endl;
// }
// vector<int> fac(int x)   
// {
// 	if(x == 0 || x == 1){
// 		return vector<int>(1,1);
// 	}
// 	while(x > lastN){
// 		Mutiple(nVec, ++lastN);
// 	}
// 	return nVec;
// }
// int main(){
//     int n;
//     while (cin>>n)
//     {
//          CoutVec(fac(n));
//     }
//     return 0;
// }
