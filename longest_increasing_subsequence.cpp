#include <iostream>

using namespace std;

int n;
int a[1001];
int table[1001];

int solve()
{
    table[0] = 1;
    int mx = -1;
    for (int i = 1; i < n; ++i)
    {
        int v = -1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
            {
                v = max(v, table[j] + 1);
            }
        }
        mx = max(mx, table[i] = v != -1 ? v : 1);
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << solve();
}