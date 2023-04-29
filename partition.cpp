#include <iostream>

using namespace std;

long long p[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    p[0] = 1;
    for (int i = 1; i <= 100; ++i)
    {
        int j = 1;
        long long res = 0;
        while (true)
        {
            int a = j * (3 * j - 1) / 2;
            if (i - a < 0)
                break;
            if (j & 1)
                res += p[i - a];
            else
                res -= p[i - a];
            a = j * (3 * j + 1) / 2;
            if (i - a < 0)
                break;
            if (j & 1)
                res += p[i - a];
            else
                res -= p[i - a];
            j++;
        }
        p[i] = res;
    }
    for (int i = 1; i <= 100; ++i)
    {
        cout << i << ' ' << p[i] << '\n';
    }
}