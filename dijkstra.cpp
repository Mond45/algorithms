#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n, vector<pair<int, ll>>());
    while (m--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        if (a == b)
            continue;
        adj[--a].emplace_back(--b, w);
        adj[b].emplace_back(a, w);
    }

    min_heap<pair<ll, int>> pq;
    pq.emplace(0, 0);
    vector<ll> d(n, INF);
    vector<int> par(n, -1);
    d[0] = 0;
    while (!pq.empty())
    {
        auto [dist, u] = pq.top();
        pq.pop();
        if (d[u] != dist)
            continue;
        for (auto [v, w] : adj[u])
        {
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
                par[v] = u;
            }
        }
    }

    if (d[n - 1] == INF)
    {
        cout << -1;
    }
    else
    {
        stack<int> s;
        int v = n - 1;
        while (v != -1)
        {
            s.push(v);
            v = par[v];
        }
        while (!s.empty())
        {
            cout << s.top() + 1 << ' ';
            s.pop();
        }
    }
}