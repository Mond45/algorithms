#include <iostream>

using namespace std;

using ui = unsigned int;

inline ui len(ui n)
{
    ui i = 1;
    while (i <= n)
    {
        i <<= 1;
    }
    return i - 1;
}

int solve(ui n, ui l, ui r, ui cl, ui cr)
{
    ui mid = (cl + cr) >> 1;
    ui res = 0;
    if (l <= mid && mid <= r)
    {
        res += n % 2;
    }
    if (n > 1)
    {
        if (max(cl, l) <= min(mid - 1, r))
        {
            res += solve(n >> 1, l, r, cl, mid - 1);
        }
        if (max(mid + 1, l) <= min(cr, r))
        {
            res += solve(n >> 1, l, r, mid + 1, cr);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ui n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r, 1, len(n));
}
