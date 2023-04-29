#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = 0;
        int j = 1;
        while (true)
        {
            if (i < j * (3 * j - 1) / 2)
                break;
            if (j & 1)
                p[i] += p[i - j * (3 * j - 1) / 2];
            else
                p[i] -= p[i - j * (3 * j - 1) / 2];
            if (i < j * (3 * j + 1) / 2)
                break;
            if (j & 1)
                p[i] += p[i - j * (3 * j + 1) / 2];
            else
                p[i] -= p[i - j * (3 * j + 1) / 2];
            j++;
        }
    }
    printf("%d", p[n]);
}