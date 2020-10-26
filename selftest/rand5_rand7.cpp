#include <iostream>
#include <ctime>
using namespace std;

int MyRandom(int n)
{
    return rand() % n;
}

// 随机生成01234
int rand5()
{
    return MyRandom(5);
}

int rand7()
{
    while (true)
    {
        // 生成 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 共15种可能
        // int x = rand5() * 3; // 错误的方式，有的数并不是3的倍数
        // int x = rand5() + rand5() + rand5(); // 有问题
        int x = rand5() * 2 + rand5(); // 有问题


        if (x >= 14)  // 剔除14, 15
            continue;
        else
            return x % 7;
    }
}

int main()
{
    int i = 0;
    int n = 7;
    int a[100] = {0};
    srand((unsigned int)time(nullptr));

    for (int i = 0; i < 7000000; i++)
    {
        a[rand7()]++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}