#include <iostream>

using namespace std;

int dp[1001][1001];
int a[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        string s;
        cin >> s;
        // cin >> a[i][j];
        for (int j = 0; j < c; ++j)
        {
            a[i][j] = s[j] == '1';
        }
    }
    for (int i = 0; i < c; ++i)
    {
        dp[0][i] = a[0][i];
    }
    for (int i = 0; i < r; ++i)
    {
        dp[i][0] = a[i][0];
    }
    int mx = -1;
    for (int i = 1; i < r; ++i)
    {
        for (int j = 1; j < c; ++j)
        {
            if (a[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                int x1 = dp[i - 1][j], x2 = dp[i - 1][j - 1], x3 = dp[i][j - 1];
                int mn = min(x1, min(x2, x3));
                mx = max(mx, dp[i][j] = mn + 1);
            }
        }
    }
    cout << mx;
}
