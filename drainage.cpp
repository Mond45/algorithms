#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int res = 1, r = v[0] + l - 1;
    for (int i = 1; i < n; ++i)
    {
        if (v[i] <= r)
            continue;
        res++;
        r = v[i] + l - 1;
    }
    cout << res << '\n';
}