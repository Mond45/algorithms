#include <iostream>

using namespace std;

int a[1001][1001];
int p[1001][1001];

inline int P(int r, int c)
{
    if (r >= 0 && c >= 0)
        return p[r][c];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    p[0][0] = a[0][0];
    for (int i = 1; i < n; ++i)
    {
        p[i][0] = p[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < m; ++i)
    {
        p[0][i] = p[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];
        }
    }
    while (k--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << P(r2, c2) - P(r2, c1 - 1) - P(r1 - 1, c2) + P(r1 - 1, c1 - 1) << '\n';
    }
}