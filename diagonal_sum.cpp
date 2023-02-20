#include <iostream>
#include <limits>

using namespace std;

int a[1001][1001];
int s[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    int res = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i)
    {
        s[0] = a[0][i];
        int best = s[0];
        for (int j = 1; j < n - i; ++j)
        {
            s[j] = max(s[j - 1] + a[j][i + j], a[j][i + j]);
            best = max(best, s[j]);
        }
        res = max(best, res);
    }
    for (int i = 1; i < n; ++i)
    {
        s[0] = a[i][0];
        int best = s[0];
        for (int j = 1; j < n - i; ++j)
        {
            s[j] = max(a[i + j][j] + s[j - 1], a[i + j][j]);
            best = max(best, s[j]);
        }
        res = max(best, res);
    }
    cout << res;
}