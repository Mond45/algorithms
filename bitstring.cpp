#include <iostream>

using namespace std;

int dp[5001][2];
int t[5001][2];

#define MOD 100000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    t[0][0] = 0;
    t[0][1] = 1;
    for (int i = 1; i <= k - 1; ++i)
    {
        dp[i][0] = 1;
        t[i][0] = i + 1;
        t[i][1] = k;
    }
    t[k - 1][1] = k;
    t[k - 1][0] = 0;
    t[k][0] = k;
    t[k][1] = k;
    dp[0][0] = 1;
    int prev = 0, current = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int s = 0; s <= k; ++s)
        {
            dp[s][current] = (dp[t[s][0]][prev] + dp[t[s][1]][prev]) % MOD;
        }
        prev ^= 1;
        current ^= 1;
    }
    cout << dp[0][prev];
}