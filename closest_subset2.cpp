#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int n, a[110], m, k, prefix[110];
int res = 1e8;

inline int get_sum(int start, int end)
{
    int res{};
    for (int i = start; i <= end && i < n; ++i)
    {
        res += a[i];
    }
    return res;
}

void dfs(int offset = 0, int cnt = 0, int sum = 0)
{
    if (cnt == m)
    {
        res = min(res, abs(sum - k));
    }
    else if (cnt < m)
    {
        if (sum >= k && sum - k >= res)
            return;
        int max_possible = get_sum(offset, offset + m - cnt);
        if (k - sum - max_possible >= res)
            return;
        for (int i = offset; i < n; ++i)
        {
            dfs(i + 1, cnt + 1, sum + a[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; ++i)
    {
        prefix[i + 1] = a[i];
        prefix[i + 1] += prefix[i];
    }
    dfs();
    cout << res;
}
