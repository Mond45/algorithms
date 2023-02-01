#include <iostream>
#include <vector>

using namespace std;

void gen(vector<vector<int>> &v, int a, int b, int x1, int x2, int y1, int y2)
{
    if (a == 0)
    {
        v[y1][x1] = b;
    }
    else
    {
        int mx = (x1 + x2) >> 1;
        int my = (y1 + y2) >> 1;
        gen(v, a - 1, b, x1, mx, y1, my);
        gen(v, a - 1, b - 1, mx + 1, x2, y1, my);
        gen(v, a - 1, b + 1, x1, mx, my + 1, y2);
        gen(v, a - 1, b, mx + 1, x2, my + 1, y2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> v(1 << a, vector<int>(1 << a));
    gen(v, a, b, 0, (1 << a) - 1, 0, (1 << a) - 1);
    for (int i = 0; i < 1 << a; ++i)
    {
        for (int j = 0; j < 1 << a; ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}