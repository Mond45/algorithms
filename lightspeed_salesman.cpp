#include <iostream>
#include <vector>

using namespace std;

int m;
vector<int> prefix;

inline int min_dist(int a, int b)
{
    if (b < a)
        swap(a, b);
    return min(prefix[b - 1] - prefix[a - 1], prefix[m] - prefix[b - 1] + prefix[a - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> m;
    prefix.resize(m + 1);
    vector<int> seq(m + 1);
    vector<pair<int, int>> portal;
    for (int i = 0; i < m; ++i)
    {
        cin >> seq[i];
        seq[i]++;
    }
    seq[m] = seq[0];
    for (int i = 1; i <= m; ++i)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        portal.emplace_back(a + 1, b + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        int res{};
        auto [pa, pb] = portal[i];
        for (int j = 1; j <= m; ++j)
        {
            int cur = seq[j], prev = seq[j - 1];
            res += min(min_dist(prev, cur), min(min_dist(prev, pb) + min_dist(pa, cur), min_dist(prev, pa) + min_dist(pb, cur)));
        }
        cout << res << '\n';
    }
}