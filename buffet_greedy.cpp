#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int f, w, n;
    cin >> f >> w >> n;
    vector<int> food(f);
    for (int i = 0; i < f; ++i)
        cin >> food[i];
    sort(food.begin(), food.end());
    int res{1};
    int r = food[0] + 2 * w;
    for (int i = 1; i < f; ++i)
    {
        if (food[i] <= r)
            continue;
        r = food[i] + 2 * w;
        res++;
    }
    cout << res;
}