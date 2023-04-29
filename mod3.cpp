#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // O(n)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v{5, 1, 8, 7, 1, 1, 2, 9, 9, 9};
    int sum = 0;
    vector<int> mod[3];
    mod[0].push_back(0);
    for (int i = 0; i < v.size(); ++i)
    {
        sum = (sum + v[i]) % 3;
        mod[sum].push_back(i + 1);
    }
    int len = -1;
    int l, r;
    for (int i = 0; i < 3; ++i)
    {
        if (mod[i].size() >= 2 && mod[i].back() - mod[i].front() > len)
        {
            r = mod[i].back() - 1;
            l = mod[i].front();
            len = mod[i].back() - mod[i].front();
        }
    }
    for (int i = l; i <= r; ++i)
    {
        cout << v[i];
    }
}