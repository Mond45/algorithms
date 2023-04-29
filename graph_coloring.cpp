#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> col;
int n;

bool dfs(int k)
{
    if (!col.empty())
    {
        int u = col.size() - 1;
        for (int v : adj[u])
        {
            if (v < col.size() && col.back() == col[v])
                return false;
        }
    }
    if (col.size() == n)
    {
        return true;
    }
    
    for (int i = 0; i < k; ++i)
    {
        col.push_back(i);
        if (dfs(k))
            return true;
        col.pop_back();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int e;
    cin >> n >> e;
    adj.assign(n, vector<int>());
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        col.clear();
        if (dfs(i))
        {
            cout << i;
            break;
        }
    }
}