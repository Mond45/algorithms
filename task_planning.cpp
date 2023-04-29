#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
stack<int> s;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    s.push(v);
}

void tsort()
{
    for (int i = 0; i < adj.size(); ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
    }
    tsort();
}