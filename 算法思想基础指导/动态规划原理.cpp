/*
 * 动态规划原理：
 * 
 * 1.确认原问题和子问题：
 * 2.确认i时刻状态：
 * 3.确认起始边界状态(i=0,1,2...)的值：
 * 4.确定状态转移方程：
 * 例如：dp[i] = dp[i - 1] + dp[i - 2]; (i >= 3)
 * 
 */


// 递归问题 ---> 重叠子问题:
// 1. 递归 + 记忆化搜索 --- 自上而下解决问题
// 2. 动态规划 --- 自底向上解决问题

#include <bits/stdc++.h>
using namespace std;

// 经典0-1背包问题
// w重量，v价值，C背包容量
// 状态转移方程
// F(i, C) = max[F(i - 1, C), v(i) + F(i - 1, c - w(i))]

// 暴力解法
// 每件物品可以放进背包，也可不放进背包，复杂度O((2^n)*n)

// 递归 自顶向下
class KnapSack
{
public:
    int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
    {
        // memo是对index，C的状态的记忆化记录, C+1表示从0到C的容量
        memo = vector<vector<int>>(w.size(), vector<int>(C + 1, -1));
        return BestValue(w, v, w.size() - 1, C);
    }

private:
    vector<vector<int>> memo;

    // 用 [0, ..., index] 的物品，填充容积为c的背包的最大价值
    int BestValue(const vector<int> &w, const vector<int> &v, int index, int C)
    {
        if (index < 0 || C <= 0)
            return 0;

        if (memo[index][C] != -1)
            return memo[index][C];

        int res = BestValue(w, v, index - 1, C);
        if (C >= w[index])
            res = max(res, v[index] + BestValue(w, v, index - 1, C - w[index]));

        memo[index][C] = res;
        return res;
    }
};

int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> value = {6, 10, 12};
    int C = 5;

    KnapSack k;
    int res = k.KnapSack01(weight, value, 5);
    cout << res << endl;
    return 0;
}

// DP 自底向上
class KnapSack
{
public:
    int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
    {
        assert(w.size() == v.size());
        int n = w.size();

        vector<vector<int>> dp(n, vector<int>(C + 1, -1));

        // 第一行，以背包容量为列，以当前可选物品的种类为行
        for (int j = 0; j <= C; j++) // j 代表当前状态下的背包容量
        {
            dp[0][j] = (j >= w[0]) ? v[0] : 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= C; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= w[i])  // 当前背包容量要比最后一个种类物品的重量大
                    dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }

        return dp[n - 1][C];
    }
};

// DP优化
// 第i行元素只依赖于第i-1行，理论上只需保留两行  
// 空间复杂度 O(2 * C) = O(C)
class KnapSack
{
public:
    int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
    {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0 || C == 0)
            return 0;

        vector<vector<int>> dp(2, vector<int>(C + 1, -1));

        // 第一行，以背包容量为列，以当前可选物品的个数为行
        for (int j = 0; j <= C; j++) // j 代表当前状态背包容量是多少
        {
            dp[0][j] = (j >= w[0]) ? v[0] : 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= C; j++)
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (j >= w[i])
                    dp[i % 2][j] = max(dp[i % 2][j], v[i] + dp[(i - 1) % 2][j - w[i]]);
            }
        }

        return dp[(n - 1) % 2][C];
    }
};

// DP优化更进一步
// 理论上只保留一行  
// 空间复杂度 O(1 * C) = O(C)
class KnapSack
{
public:
    int KnapSack01(const vector<int> &w, const vector<int> &v, int C)
    {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0 || C == 0)
            return 0;

        vector<int> dp(C + 1, -1);

        // 第一行，以背包容量为列，以当前可选物品的个数为行
        for (int j = 0; j <= C; j++) // j 代表当前状态背包容量是多少
        {
            dp[j] = (j >= w[0]) ? v[0] : 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = C; j >= w[i]; j--)
            {
                if (j >= w[i])
                    dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
            }
        }

        return dp[C];
    }
};

int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> value = {6, 10, 12};
    int C = 5;

    KnapSack k;
    int res = k.KnapSack01(weight, value, 5);
    cout << res << endl;
    return 0;
}
