#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e8;
int r, c;
vector<vector<int>> cost;
vector<vector<pair<int, int>>> adj;
const vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<int> d;

void solve()
{
    d.assign(r * c, INF);
    d[0] = 0;
    set<pair<int, int>> s;
    s.emplace(0, 0);
    while (!s.empty())
    {
        auto u = s.begin()->second;
        s.erase(s.begin());
        for (auto [v, w] : adj[u])
        {
            // p(v, w)
            if (d[u] + w < d[v])
            {
                s.erase({d[v], v});
                d[v] = d[u] + w;
                s.emplace(d[v], v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    cost.assign(r, vector<int>(c));
    adj.assign(r * c, vector<pair<int, int>>());
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> cost[i][j];
        }
    }
    cost[0][0] = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            for (auto [dx, dy] : neighbors)
            {
                int ni = i + dy, nj = j + dx;
                if (0 <= ni && ni < r && 0 <= nj && nj < c)
                {
                    adj[ni * c + nj].emplace_back(i * c + j, cost[i][j]);
                }
            }
        }
    }
    solve();
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << d[i * c + j] << ' ';
        }
        cout << '\n';
    }
}