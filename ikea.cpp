#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> req;
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        req.emplace_back(a, b);
    }
    unordered_map<int, int> m;
    for (int z = 0; z < 5; ++z)
    {
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            m[x] = i;
        }
        bool success = true;
        for (auto [a, b] : req)
        {
            if (m[a] > m[b])
            {
                success = false;
                break;
            }
        }
        cout << (success ? "SUCCESS\n" : "FAIL\n");
    }
}