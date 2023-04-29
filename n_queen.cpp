#include <iostream>
#include <vector>

using namespace std;

vector<int> col;
vector<bool> used;
int cnt;
int n;

constexpr int _abs(int x)
{
    return x < 0 ? -x : x;
}

void dfs()
{
    if (!col.empty())
    {
        for (int i = 0; i < col.size() - 1; ++i)
        {
            int j = col[i];
            if (_abs(col.size() - i - 1) == _abs(j - col.back()))
            {
                return;
            }
        }
    }
    if (col.size() == n)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                col.push_back(i);
                used[i] = true;
                dfs();
                col.pop_back();
                used[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    col.reserve(n);
    used.assign(n, false);
    dfs();
    cout << cnt;
}