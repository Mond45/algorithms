#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int suffix, best;
    cin >> suffix;
    best = suffix;
    for (int i = 1; i < n; ++i)
    {
        int a;
        cin >> a;
        suffix = max(a, a + suffix);
        best = max(suffix, best);
    }
    cout << best;
}