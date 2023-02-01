#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<int> chef;

inline ll last(ll t)
{
    ll res = 0;
    for (int c : chef)
    {
        res += ((t + 1) / c) + (((t + 1) % c) != 0);
    }
    return res;
}

ll solve(ll q, ll low = 0, ll hi = (ll)1e15, ll res = 0)
{
    ll mid = (low + hi) >> 1;
    if (low > hi)
        return res;
    ll cur = last(mid);
    if (cur >= q)
        return solve(q, low, mid - 1, mid);
    else if (cur < q)
        return solve(q, mid + 1, hi, res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a;
    cin >> n >> a;
    chef.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> chef[i];
    }
    while (a--)
    {
        ll q;
        cin >> q;
        cout << solve(q) << '\n';
    }
}