#include <iostream>
#include <limits>

using namespace std;

int s[110], n, dp[110][110];

int solve(int l, int r)
{
    if (l == r)
        return 0;
    if (dp[l][r])
        return dp[l][r];
    int res = numeric_limits<int>::max();
    for (int i = l; i < r; ++i)
    {
        // [l,i] [i+1,r]
        res = min(res, solve(l, i) + solve(i + 1, r) + s[l] * s[i + 1] * s[r + 1]);
    }
    return dp[l][r] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        cin >> s[i];
    }
    cout << solve(0, n - 1);
}