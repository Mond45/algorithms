#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    // stirling number of the second kind
    int s[501][501];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (i == j || j == 1)
                s[i][j] = 1;
            else
                s[i][j] = (j * s[i - 1][j] + s[i - 1][j - 1]) % 1997;
        }
    }
    cout << s[n][k];
}