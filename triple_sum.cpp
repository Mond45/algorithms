#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, m;

inline pair<int, int> solve2(int x)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (v[i] + v[j] == x)
            return make_pair(i, j);
        else if (v[i] + v[j] < x)
            i++;
        else
            j--;
    }
    return make_pair(-1, -1);
}

inline bool solve(int x)
{
    for (int i = 0; i < n; ++i)
    {
        auto p = solve2(x - v[i]);
        if (p.first != -1 && p.second != -1 && p.first != i && p.second != i)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        cout << (solve(x) ? "YES\n" : "NO\n");
    }
}