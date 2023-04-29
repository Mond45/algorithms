#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int a, b, w;
};
vector<edge> edges;
vector<int> d;

#define INF 1000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e, s;
    cin >> n >> e >> s;
    edges.assign(e, edge());
    d.assign(n, INF);
    d[s] = 0;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(edge{a, b, w});
    }
    bool any = false;
    for (int i = 0; i < n; ++i)
    {
        any = false;
        for (auto &e : edges)
        {
            if (d[e.a] < INF)
            {
                if (d[e.a] + e.w < d[e.b])
                {
                    d[e.b] = d[e.a] + e.w;
                    any = true;
                }
            }
        }
    }
    if (any)
    {
        cout << -1;
    }
    else
    {

        for (int i : d)
        {
            cout << i << ' ';
        }
    }
}