#include <iostream>
#include <vector>

using namespace std;

using adjList = vector<vector<int>>;

adjList adj;
vector<bool> visited;
int count = 0;

void dfs(int start)
{
    visited[start] = true;
    for (int v : adj[start])
    {
        if (!visited[v])
            dfs(v);
    }
}

void solve()
{
    visited.assign(adj.size(), false);
    for (int v = 0; v < adj.size(); ++v)
    {
        if (!visited[v])
        {
            dfs(v);
            count++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e;
    cin >> v >> e;
    adj.assign(v, vector<int>());
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    solve();
    cout << count;
}