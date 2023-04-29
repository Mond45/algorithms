#include <iostream>
#include <unordered_map>

using namespace std;

int a[5001][5001];
int deg[5001];

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
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i][j])
            {
                deg[i]++;
                deg[j]++;
            }
        }
    }
    int mx = -1;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        cnt[deg[i]]++;
        mx = max(mx, deg[i]);
    }
    for (int i = 0; i <= mx; ++i)
    {
        cout << cnt[i] << ' ';
    }
}