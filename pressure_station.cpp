#include <iostream>
#include <limits>

using namespace std;

int dp[10'010];
int cost[10'010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
        {
            dp[i] = cost[i];
        }
        else
        {
            int mn = numeric_limits<int>::max();
            for (int j = max(0, i - 2 * k - 1); j <= i - 1; ++j)
            {
                mn = min(mn, dp[j]);
            }
            dp[i] = mn + cost[i];
        }
    }
    int res = numeric_limits<int>::max();
    for (int i = max(0, n - k - 1); i < n; ++i)
    {
        res = min(res, dp[i]);
    }
    cout << res;
}