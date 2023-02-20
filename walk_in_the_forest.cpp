#include <iostream>

using namespace std;

int a[501][501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < m; ++i)
    { // fill first row
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; ++i)
    { // fill first column
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            dp[i][j] = max(max(dp[i][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]), dp[i - 1][j - 1] + (a[i][j] << 1));
        }
    }
    cout << dp[n - 1][m - 1];
}