#include <iostream>
#include <vector>

using namespace std;

vector<int> g;

void gen_seq(int n)
{
    int idx = 1;
    while (g.back() < n)
    {
        g.push_back(2 * g.back() + idx + 3);
        idx++;
    }
}

char solve(int k, int pos)
{
    if (k == 0)
    {
        return pos == 1 ? 'g' : 'a';
    }
    int lp = g[k - 1];
    if (pos <= lp)
    {
        return solve(k - 1, pos);
    }
    else if (pos <= lp + k + 3)
    {
        return pos == lp + 1 ? 'g' : 'a';
    }
    else
    {
        return solve(k - 1, pos - (lp + k + 3));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.reserve(100);
    g.push_back(3);
    gen_seq(n);
    // for (int i : g)
    // {
    //     cout << i << '\n';
    // }
    cout << solve(g.size() - 1, n);
}