#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// day event label
using event = tuple<int, int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    queue<int> plants, stores; //(time,label)
    vector<event> events;
    while (k--)
    {
        int d, e, l;
        cin >> d >> e >> l;
        events.emplace_back(d, e, l);
    }
    sort(events.begin(), events.end());
    for (auto [d, e, l] : events)
    {
        if (e == 0) // plant production
        {
            if (stores.empty())
            {
                plants.emplace(l);
                cout << 0 << '\n';
            }
            else
            {
                auto sl = stores.front();
                stores.pop();
                cout << sl << '\n';
            }
        }
        else if (e == 1) // store request
        {
            if (plants.empty())
            {
                stores.emplace(l);
                cout << 0 << '\n';
            }
            else
            {
                auto pl = plants.front();
                plants.pop();
                cout << pl << '\n';
            }
        }
    }
}