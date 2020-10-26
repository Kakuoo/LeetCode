#include <iostream>
using namespace std;

int main()
{
    int n;
    int ret = 0;

    cin >> n;
    int *tree = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    // 计算：先处理两端，再遍历中间
    if (tree[0] + tree[1] == 0)
    {
        tree[0] = 1;
        ret++;
    }
    else if (tree[n - 1] + tree[n - 2] == 0)
    {
        tree[n - 1] = 1;
        ret++;
    }

    for (int i = 1; i < n - 2; i++)
    {
        if (tree[i - 1] + tree[i] + tree[i + 1] == 0)
        {
            tree[i] = 1;
            ret++;
        }
        else
        {
            continue;
        }
    }

    cout << ret;
    
    return 0;
}
