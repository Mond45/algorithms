#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int> d;
vector<bool> visited;
int n;

int solve()
{
    d.assign(n, INF);
    visited.assign(n, false);
    d[0] = 0;
    min_heap<pair<int, int>> pq;

    pq.emplace(0, 0); //(w, u)
    while (!pq.empty())
    {
        auto u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto [v, w] : adj[u])
        {
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
    return d[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n, vector<pair<int, int>>());
    int c;
    cin >> c;
    adj[0].emplace_back(1, c);
    adj[1].emplace_back(0, c);
    for (int i = 2; i < n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int t, p;
            cin >> t >> p;
            adj[i].emplace_back(--t, p);
            adj[t].emplace_back(i, p);
        }
        cout << solve() << ' ';
    }
    return 0;
}
