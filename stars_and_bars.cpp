#include <iostream>
#include <vector>

using namespace std;

vector<int> res;
int cnt;

void gen(int n, int m)
{
    if (n == 0)
    {
        if (m == 0)
        {
            cnt++;
            for (int i : res)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        for (int i = 1; i <= m - n + 1; ++i)
        {
            res.push_back(i);
            gen(n - 1, m - i);
            res.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    gen(4, 10);
    cout << cnt;
}