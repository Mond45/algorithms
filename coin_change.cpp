#include <iostream>

using namespace std;

int a[10010];
int d[21];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = n - 1; i >= 0; --i)
    {
        cin >> d[i];
        a[d[i]] = 1;
    }
    for (int i = 2; i <= m; ++i)
    {
        if (a[i] != 1)
        {
            int mn = 9000000;
            for (int j = 0; j < n; ++j)
            {
                if (d[j] > i)
                    break;
                mn = min(mn, a[i - d[j]] + 1);
            }
            a[i] = mn;
        }
    }
    cout << a[m];
}