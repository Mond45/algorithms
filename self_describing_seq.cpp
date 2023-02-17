#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int q[1001];

inline int find_lt(int val)
{
    int res = -1;
    int l = 1;
    int r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a.at(mid) < val)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}

inline int find_le(int val)
{
    int res = -1;
    int l = 1, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a.at(mid) == val)
            return mid;
        else if (a.at(mid) < val)
        {
            res = mid;
            l = mid + 1;
        }
        else
        { // a[mid]>val
            r = mid - 1;
        }
    }
    return res;
}

void gen_seq(int mx)
{
    int idx = a.size();
    while (a.back() < mx)
    {
        a.push_back(a.back() + find_lt(idx));
        idx++;
    }
}

int32_t main()
{
    // freopen("io/in.txt", "r", stdin);
    // freopen("io/out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> q[0];
    int mx = q[0];
    for (int i = 1; i < n; ++i)
    {
        cin >> q[i];
        mx = max(mx, q[i]);
    }
    a.reserve(1000000);
    for (int i : {0, 1, 2, 4})
    {
        a.push_back(i);
    }
    gen_seq(mx);
    for (int i = 0; i < n; ++i)
    {
        int n = find_le(q[i]);
        cout << n << '\n';
    }
    // cout << sz;
}