#include <iostream>

using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cin >> dp[i][j];
        }
    }
    string res;
    int i = n, j = m;
    while (i && j)
    {
        if (x[i - 1] == y[j - 1])
        {
            res = x[i - 1] + res;
            i -= 1;
            j -= 1;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i -= 1;
        }
        else
        {
            j -= 1;
        }
    }
    cout << res;
}