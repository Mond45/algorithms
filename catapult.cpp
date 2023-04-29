#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> adjT;
vector<bool> visited;
stack<int> order;

void dfs1(int u)
{
    visited[u] = true;
    for (int v : adjT[u])
    {
        if (!visited[v])
            dfs1(v);
    }
    order.push(u);
}

void dfs1()
{
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
}

int cnt = 0;
vector<int> Cnt;

void dfs2(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs2(v);
    }
    cnt++;
}

void dfs2()
{
    visited.assign(n, false);
    while (!order.empty())
    {
        int u = order.top();
        order.pop();
        if (!visited[u])
        {
            cnt = 0;
            dfs2(u);
            Cnt.push_back(cnt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n, vector<int>());
    adjT.assign(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int to;
            cin >> to;
            adj[i].push_back(to);
            adjT[to].push_back(i);
        }
    }
    dfs1();
    dfs2();
    sort(Cnt.begin(), Cnt.end());
    for (int i : Cnt)
    {
        cout << i << ' ';
    }
}