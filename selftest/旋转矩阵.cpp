/** 
 * 有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
 * 给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于300。
 * 测试样例：
 * [[1,2,3],[4,5,6],[7,8,9]],3
 * 返回：[[7,4,1],[8,5,2],[9,6,3]]
 */

#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// 方法一
#define MAX_NUM 300

int main()
{
    int a[MAX_NUM][MAX_NUM], n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            cout << a[j][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}

// 方法二
vector<vector<int>> rotate_matrix(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> res = mat;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[j][n - 1- i] = mat[i][j];
        }
    }
    return res;
}

int main()
{
    // SetConsoleOutputCP(65001);
    int N, tmp;  // 数组阶数, 临时输入
    cin >> N;
    cout << "Input array number " << endl;
    
    vector<vector<int>> mat(N, vector<int>(N, 0)), res;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> tmp;
            mat[i][j] = tmp;
        }
    }
    res = rotate_matrix(mat, N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}