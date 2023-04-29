#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v; // (y,x)

vector<pair<int, int>> pareto(int l, int r)
{
    if (l == r)
    {
        return {v[l]};
    }
    else
    {
        int mid = (l + r) >> 1;
        auto a = pareto(l, mid);
        auto b = pareto(mid + 1, r);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<pair<int, int>> res;
        for (auto &p : a)
        {
            auto it = upper_bound(b.begin(), b.end(), p);
            if (it == b.end() || it->second < p.second)
            {
                res.emplace_back(p);
            }
        }
        for (auto &p : b)
        {
            auto it = upper_bound(a.begin(), a.end(), p);
            if (it == a.end() || it->second < p.second)
            {
                res.emplace_back(p);
            }
        }
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.reserve(n);
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(y, x);
    }
    sort(v.begin(), v.end());
    cout << pareto(0, v.size() - 1).size();
}
