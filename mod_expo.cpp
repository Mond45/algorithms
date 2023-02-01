#include <iostream>

using namespace std;

using ll = long long;

constexpr ll sqr(ll x)
{
    return x * x;
}

inline ll mod_expo(ll x, ll n, ll k)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x % k;
    if (n & 1)
    { // odd
        return (x * sqr(mod_expo(x, n >> 1, k))) % k;
    }
    else
    { // even
        return sqr(mod_expo(x, n >> 1, k)) % k;
    }
}

int main()
{
    // calculate x^n mod k
    int x, n, k;
    cin >> x >> n >> k;
    cout << mod_expo(x, n, k);
}