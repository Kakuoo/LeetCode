#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int K;
    // cin >> N >> K;
    cin >> K >> N;

    int res = 0;
    vector<int> dp(K + 1);
    for (; dp[K] < N; ++res)
    {
        for (int i = K; i > 0; --i)
        {
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    cout << res;

    return 0;
}
