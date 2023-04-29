#include <iostream>

using namespace std;

using ll = long long;

ll p[500'010];
int n, m, k;

inline ll sum(int a, int b)
{
    return p[b + 1] - p[a];
}

inline ll solve(int start, ll c)
{
    int l = start, r = n - 1;
    ll res = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        ll cost = sum(start, mid) + k * (mid - start + 1);
        if (cost <= c)
        {
            res = sum(start, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return max(res, 0ll);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    while (m--)
    {
        int s;
        ll c;
        cin >> s >> c;
        cout << solve(s, c) << '\n';
    }
}