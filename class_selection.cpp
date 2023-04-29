#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
vector<pii> interval;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int start;
        cin >> start;
        interval.emplace_back(start, 0);
    }
    for (int i = 0; i < n; ++i)
    {
        int end;
        cin >> end;
        interval[i].second = end;
    }
    sort(interval.begin(), interval.end(), [](const pii &a, const pii &b)
         { return a.second < b.second; });
    int cnt = 1, last = 0;
    for (int i = 1; i < n; ++i)
    {
        if (interval[i].first >= interval[last].second)
        {
            last = i;
            cnt++;
        }
    }
    cout << cnt;
}