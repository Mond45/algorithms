#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using pff = pair<double, double>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double W;
    int n;
    cin >> W >> n;
    vector<pff> items(n); // value, weight
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].first;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].second;
    }
    sort(items.begin(), items.end(), [](const pff &a, const pff &b)
         {
        //a.first/a.second<b.first/b.second;
        return a.first*b.second>b.first*a.second; });
    double res{};
    for (auto [v, w] : items)
    {
        if (W >= w)
        {
            res += v;
            W -= w;
        }
        else
        {
            res += (W / w) * v;
            break;
        }
    }
    printf("%.4f", res);
}