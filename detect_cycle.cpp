#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

bool dfs(int start, int parent)
{
    visited[start] = true;
    for (int i : adj[start])
    {
        if (i == parent)
            continue;
        if (visited[i])
            return true;
        if (dfs(i, start))
            return true;
    }
    return false;
}

bool has_cycle()
{
    visited.assign(adj.size(), false);
    for (int i = 0; i < adj.size(); ++i)
    {
        if (!visited[i] && dfs(i, -1))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        adj.assign(n, vector<int>());
        for (int i = 0; i < e; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << (has_cycle() ? "YES\n" : "NO\n");
    }
}