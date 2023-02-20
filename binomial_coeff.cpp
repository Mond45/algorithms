#include <iostream>

using namespace std;

int c[40][40]; // c[n][k]

int solve(int n, int k)
{
    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    return c[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
}