#include <algorithm>
#include <iostream>

using namespace std;

long long pos[100001];

long long p, k, a, b;

// inline long long lowerbound(long long value, long long l, long long u)
// {
//     long long res = k;
//     while (l <= u)
//     {
//         long long mid = (l + u) >> 1;
//         if (pos[mid] >= value)
//         {
//             res = mid;
//             u = mid - 1;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return res;
// }

// inline long long upperbound(long long value, long long l, long long u)
// {
//     long long res = k;
//     while (l <= u)
//     {
//         long long mid = (l + u) >> 1;
//         if (pos[mid] > value)
//         {
//             res = mid;
//             u = mid - 1;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return res;
// }

long long solve(long long l, long long r)
{
    long long lb = k;
    long long left = 0, right = k - 1;

    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        if (pos[mid] >= l)
        {
            lb = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    long long ub = k;
    left = 0;
    right = k - 1;
    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        if (pos[mid] > r)
        {
            ub = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    long long m = ub - lb;
    if (m == 0)
        return a;
    if (l == r)
        return b * m;
    long long mid = (l + r) >> 1;
    return min(b * m * (r - l + 1), solve(l, mid) + solve(mid + 1, r));
}

int main()
{
    // freopen("io/in.txt", "r", stdin);
    cin >> p >> k >> a >> b;
    for (int i = 0; i < k; ++i)
    {
        cin >> pos[i];
    }
    sort(pos, pos + k);
    cout << solve(1, 1 << p);
    // cout << upperbound(1, 0, k - 1);
}