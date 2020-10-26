#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int num = 0;
vector<int> mem;

// 记忆化搜索
int fib(int n)
{
    num++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (mem[n] == -1)
        mem[n] = fib(n - 1) + fib(n - 2);

    return mem[n];
}

// DP
int fib2(int n)
{
    vector<int> memo(n + 1, -1); 

    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main()
{
    int n = 45;
    mem = vector<int> (n + 1, -1);

    clock_t time_start = clock();
    cout << fib2(n) << endl;
    clock_t time_end = clock();
    cout << double(time_end - time_start) / CLOCKS_PER_SEC << endl; 
    cout << num << endl;
    return EXIT_SUCCESS;
}