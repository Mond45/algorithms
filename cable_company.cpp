#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int a, b, w;
    bool operator<(const edge &other)
    {
        return w < other.w;
    }
};

const int INF = 1e8;
int n;
vector<edge> edges;
vector<int> par, rnk;

void make_set(int i)
{
    par[i] = i;
}

int find_set(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find_set(par[i]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

int solve()
{
    par.assign(n, 0);
    rnk.assign(n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        make_set(i);
    }
    for (auto [a, b, w] : edges)
    {
        if (find_set(a) != find_set(b))
        {
            res += w;
            union_set(a, b);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int k = 0; k < n - i - 1; ++k)
        {
            int cost;
            cin >> cost;
            edges.emplace_back(edge{i, k, cost});
        }
    }
    sort(edges.begin(), edges.end());
    cout << solve();
}