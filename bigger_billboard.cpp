#include <iostream>
#include <queue>

using namespace std;

int a[10'001], dp[10'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    priority_queue<int> pq;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    int res = -1;
    for (int i = 3; i < n; ++i)
    {
        pq.push(dp[i - 3]);
        res = max(res, dp[i] = pq.top() + a[i]);
    }
    cout << res;
}