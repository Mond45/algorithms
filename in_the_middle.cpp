#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> d[3];
int t[3];
int n;

void solve(int i)
{
    queue<int> q;
    q.push(t[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (d[i][v] == INF)
            {
                d[i][v] = d[i][u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n, vector<int>());
    cin >> t[0] >> t[1] >> t[2];
    t[0]--;
    t[1]--;
    t[2]--;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int e;
            cin >> e;
            adj[i].emplace_back(--e);
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        d[i].assign(n, INF);
        d[i][t[i]] = 0;
        solve(i);
    }
    int res = INF;
    for (int i = 0; i < n; ++i)
    {
        res = min(res, max(max(d[0][i], d[1][i]), d[2][i]));
    }
    cout << res;
    return 0;
}
