#include <iostream>
#include <set>

using namespace std;

int a[200'001];
int s[200'001];

int main()
{
    // O(n log(n))
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    s[0] = a[0];
    for (int i = 1; i < 2 * n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    int ms = s[0];
    int res = ms;
    for (int i = 1; i < n; ++i)
    {
        ms = max(ms + a[i], a[i]);
        res = max(res, ms);
    }
    multiset<int> slider;
    for (int i = 1; i < n; ++i)
    {
        slider.insert(s[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, s[i + n - 1] - *slider.begin());
        slider.erase(s[i]);
        slider.insert(s[i + n - 1]);
    }
    cout << res;
}