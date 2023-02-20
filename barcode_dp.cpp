#include <iostream>

using namespace std;

int choose(int n, int k)
{
    static int a[50][50];
    if (k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else if (a[n][k])
        return a[n][k];
    return a[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    for (int i = 0; i <= k + 1; ++i)
    {
        int x = n - 1 - m * i;
        if (x < 0)
            break;
        if (i & 1)
        { // odd
            res -= choose(k + 1, i) * choose(x, k);
        }
        else
        { // even
            res += choose(k + 1, i) * choose(x, k);
        }
    }
    cout << res;
}