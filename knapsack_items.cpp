#include <iostream>
#include <vector>

using namespace std;

int dp[510][510];
int w[510];
int v[510];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    vector<int> res;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cin >> dp[i][j];
        }
    }
    int i = n, j = m;
    while (i && j)
    {
        if (j >= w[i] && dp[i][j] != dp[i - 1][j])
        {
            res.push_back(i);
            j -= w[i];
            i--;
        }
        else
        {
            i--;
        }
    }
    cout << res.size() << '\n';
    for (int i : res)
    {
        cout << i << ' ';
    }
}