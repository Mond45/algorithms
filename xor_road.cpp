#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int a, b;
    unsigned long long w;
    bool operator<(const edge &other)
    {
        return w < other.w;
    }
};
int n;
vector<int> par;
vector<int> rnk;
vector<unsigned long long> val;
vector<edge> edges;

void make_set(int i)
{
    par[i] = i;
    rnk[i] = 0;
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

unsigned long long solve()
{
    unsigned long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        make_set(i);
    }
    for (auto [a, b, w] : edges)
    {

        if (find_set(a) != find_set(b))
        {
            res -= w;
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
    par.assign(n, 0);
    rnk.assign(n, 0);
    val.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            edges.emplace_back(edge{i, j, -(val[i] ^ val[j])});
        }
    }
    sort(edges.begin(), edges.end());
    cout << solve();
}