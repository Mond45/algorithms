#include <iostream>

using namespace std;

int a[101][101];
int dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    int mx = -1;
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            if (i == n - 1)
                mx = max(mx, dp[i][j]);
        }
    }
    cout << mx;
}