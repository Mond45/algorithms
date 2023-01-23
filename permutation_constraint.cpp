#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> constraint;
bool chosen[21];

void permute(int n, vector<int> &p)
{
    if (p.size() == n)
    {
        for (int i : p)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (chosen[i])
                continue;
            bool con = false;
            for (auto &c : constraint)
            {
                if (i == c.second && !chosen[c.first])
                {
                    con = true;
                    break;
                }
            }
            if (con)
                continue;
            chosen[i] = true;
            p.push_back(i);
            permute(n, p);
            chosen[i] = false;
            p.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        constraint.emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i)
        chosen[i] = false;
    std::vector<int> result;
    permute(n, result);
}