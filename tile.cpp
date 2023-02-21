#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int a[11];
unordered_map<int, int> dp[11];
vector<pair<int, int>> tmp;
int sq[100];

constexpr int sqr(int n)
{
    return n * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 100; ++i)
    {
        sq[i] = (i + 1) * (i + 1);
    }
    for (int i = 0; i < 100; ++i)
    {
        dp[0][sq[i]] = sqr(a[0] - i - 1);
    }
    for (int i = 1; i < n; ++i)
    {
        tmp.clear();
        for (int j = 0; j < 100; ++j)
        {
            if (sq[j] > m)
                break;
            tmp.emplace_back(sq[j], sqr(a[i] - 1 - j));
        }
        for (auto &v : dp[i - 1])
        {
            for (auto &p : tmp)
            {
                if (v.first + p.first > m)
                    break;
                auto it = dp[i].find(v.first + p.first);
                if (it != dp[i].end())
                {
                    it->second = min(it->second, v.second + p.second);
                }
                else
                {
                    dp[i][v.first + p.first] = v.second + p.second;
                }
            }
        }
    }
    auto it = dp[n - 1].find(m);
    if (it != dp[n - 1].end())
    {
        cout << it->second;
    }
    else
    {
        cout << -1;
    }
}