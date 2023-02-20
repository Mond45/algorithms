#include <iostream>

using namespace std;

int a[1'000'010];
int dp[1'000'010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = a[2] + max(dp[0], dp[1]);
    for (int i = 3; i < n; ++i)
    {
        dp[i] = a[i] + max(max(dp[i - 1], dp[i - 2]), dp[i - 3]);
    }
    cout << dp[n - 1];
}