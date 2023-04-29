#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool e[101][101];
vector<vector<int>> adj;
vector<bool> visited;
vector<int> d;

void bfs()
{
    queue<int> q;
    q.push(0);
    d[0] = 0;
    visited[0] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    adj.assign(r * c, vector<int>());
    d.assign(r * c, -1);
    visited.assign(r * c, false);
    for (int i = 0; i < r; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; ++j)
        {
            if (s[j] == '.')
                e[i][j] = true;
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (e[i][j])
            {
                auto &v = adj[i * c + j];
                if (i > 0 && e[i - 1][j])
                    v.push_back((i - 1) * c + j);
                if (i < r && e[i + 1][j])
                    v.push_back((i + 1) * c + j);
                if (j > 0 && e[i][j - 1])
                    v.push_back(i * c + j - 1);
                if (j < c && e[i][j + 1])
                    v.push_back(i * c + j + 1);
            }
        }
    }
    bfs();
    cout << d[r * c - 1];
}