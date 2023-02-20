#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a[10'001];
int dp[10'001];

int main()
{
    priority_queue<int> pq;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = a[1];
    int res = -1;
    for (int i = 2; i < n; ++i)
    {
        pq.push(dp[i - 2]);
        res = max(res, dp[i] = a[i] + pq.top());
    }
    cout << res;
}