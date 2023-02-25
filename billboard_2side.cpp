#include <iostream>
#include <queue>

using namespace std;

enum
{
    L,
    R
};

int dp[200'001][2];
int l[200'001], r[200'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w, k;
    cin >> n >> w >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> r[i];
    }
    priority_queue<int> pl, pr;
    int res = -1;
    for (int i = 0; i <= w; ++i)
    {
        dp[i][L] = l[i];
        dp[i][R] = r[i];
    }
    for (int i = w + 1; i < n; ++i)
    {
        pl.push(dp[i - w - 1][L]);
        pr.push(dp[i - w - 1][R]);
        dp[i][L] = pr.top() + l[i];
        dp[i][R] = pl.top() + r[i];
        res = max(res, max(dp[i][L], dp[i][R]));
    }
    cout << res;
}