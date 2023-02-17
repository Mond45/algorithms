#include <iostream>
#include <set>

using namespace std;

int a[200'010];
int sum[200'010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<int> window;
    int n, w;
    cin >> n >> w;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s += a[i];
        sum[i] = s;
    }
    int suffix = a[0], best = a[0];
    int left = sum[0];
    window.insert(sum[0]);
    for (int i = 1; i < w; ++i)
    {
        window.insert(sum[i]);
        suffix = max(a[i], suffix + a[i]);
        best = max(best, suffix);
    }
    for (int i = w; i < n; ++i)
    {
        int cur = sum[i] - *window.begin();
        best = max(cur, best);
        if (i + 1 < n)
        {
            window.insert(sum[i]);
            window.erase(left);
            left = sum[i - w + 1];
        }
    }
    cout << best;
}