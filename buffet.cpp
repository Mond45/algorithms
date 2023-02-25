#include <iostream>

using namespace std;

int d[200'010];
int n, k, m;

inline int solve(int wanted, int start)
{
    int res = -1;
    int l = start, u = n;
    while (l <= u)
    {
        int mid = (l + u) >> 1;
        if (d[mid] - d[start - 1] - m * (mid - start + 1) >= wanted)
        {
            res = mid;
            u = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    cin >> d[1];
    for (int i = 2; i <= n; ++i)
    {
        int v;
        cin >> v;
        d[i] = d[i - 1] + v;
    }
    for (int i = 0; i < k; ++i)
    {
        int start, wanted;
        cin >> start >> wanted;
        cout << solve(wanted, start) << '\n';
    }
}