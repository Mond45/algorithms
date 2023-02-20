#include <iostream>

using namespace std;

int a[10'001];
int s[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    const int M = 1000003;
    for (int i = 0; i < k; ++i)
    {
        cin >> s[i];
    }
    a[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int val = 0;
        for (int j = 0; j < k; ++j)
        {
            if (s[j] <= i)
            {
                val = (val + a[i - s[j]] % M) % M;
            }
        }
        a[i] = val;
    }
    cout << a[n];
}