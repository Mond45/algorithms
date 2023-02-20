#include <iostream>

using namespace std;

int dp[510][510];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    for (int i = 0; i < x.length(); ++i)
    {
        for (int j = 0; j < y.length(); ++j)
        {
            if (x[i] == y[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[x.length()][y.length()];
}