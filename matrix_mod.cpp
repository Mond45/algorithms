#include <iostream>
#include <vector>

using namespace std;

vector<int> mulmod(const vector<int> &a, const vector<int> &b, int k)
{
    return {((a[0] * b[0]) % k + (a[1] * b[2]) % k) % k, ((a[0] * b[1]) % k + (a[1] * b[3]) % k) % k,
            ((a[2] * b[0]) % k + (a[3] * b[2]) % k) % k, ((a[2] * b[1]) % k + (a[3] * b[3]) % k) % k};
}

vector<int> solve(const vector<int> &a, int n, int k)
{
    if (n == 0)
    {
        return {1, 0, 0, 1};
    }
    if (n == 1)
    {
        return mulmod(a, {1, 0, 0, 1}, k);
    }
    auto v = solve(a, n >> 1, k);
    if (n & 1)
    { // odd
        return mulmod(mulmod(v, v, k), a, k);
    }
    else
    {
        return mulmod(v, v, k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    vector<int> v{a, b, c, d};
    auto res = solve(v, n, k);
    for (int i : res)
        cout << i << ' ';
}