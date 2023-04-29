#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int find(int d)
{
    int l = 0, r = h.size() - 1, res{-1};
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (h[m] <= d)
        {
            res = h[m];
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return res;
}

int days(int k)
{
    int res{};
    int d = 0;
    while (d != h.back())
    {
        d += k;
        d = find(d);
        res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    h.resize(n);
    cin >> h[0];
    int l{h[0]};
    for (int i = 1; i < n; ++i)
    {
        cin >> h[i];
        l = max(l, h[i] - h[i - 1]);
    }
    int r = h.back();
    int res{};
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (days(m) <= d)
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << res << ' ' << days(res);
}