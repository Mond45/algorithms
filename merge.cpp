#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    deque<int> v;
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        if (k >= n - i - 1)
        {
            res.push_back(v.back());
            v.pop_back();
            k -= n - i - 1;
        }
        else
        {
            res.push_back(v.front());
            v.pop_front();
        }
    }
    for (int i : res)
    {
        cout << i << ' ';
    }
}