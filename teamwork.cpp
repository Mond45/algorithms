#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> task(m);
    vector<vector<int>> v(n, {0});
    for (int i = 0; i < m; ++i)
    {
        cin >> task[i];
    }
    int idx = 0;

    sort(task.begin(), task.end());
    for (auto t : task)
    {
        v[idx].push_back(v[idx].back() + t);
        idx++;
        if (idx == n)
            idx = 0;
    }
    double res{};
    for (auto &m : v)
    {
        for (auto i : m)
        {
            res += i;
        }
    }
    printf("%.3f", res / m);
}