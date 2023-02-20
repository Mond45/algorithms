#include <iostream>

using namespace std;

int dp[4010], a[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> a[0] >> a[1] >> a[2];
    int mn = min(min(a[0], a[1]), a[2]);
    for (int i = mn; i <= n; ++i)
    {
        int r0 = 0, r1 = 0, r2 = 0;
        if (i - a[0] >= mn)
        {
            r0 = dp[i - a[0]];
        }
        if (i - a[1] >= mn)
        {
            r1 = dp[i - a[1]];
        }
        if (i - a[2] >= mn)
        {
            r2 = dp[i - a[2]];
        }
        int mx = max(max(r0, r1), r2);
        // dp[i] = 1 + ;
        if (mx)
        {
            dp[i] = 1 + mx;
        }
        else
        {
            int r = 0;
            for (int j = 0; j < 3; ++j)
            {
                if (i % a[j] == 0)
                    r = i / a[j];
            }
            dp[i] = r;
        }
    }
    cout << dp[n];
}
