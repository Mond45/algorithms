#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

inline unsigned char quad(int x1, int x2, int y1, int y2, int x, int y)
{
    bool left = x <= (x1 + x2) / 2;
    bool top = y <= (y1 + y2) / 2;
    if (!left && top)
        return 1;
    else if (left && top)
        return 2;
    else if (left && !top)
        return 3;
    else
        return 4;
}

int orient[] = {0, 1, 0, 2, 3};
vector<tuple<int, int, int>> cmd;

void solve(int l, int x1, int x2, int y1, int y2, int x, int y)
{
    int q = quad(x1, x2, y1, y2, x, y);
    if (l == 2)
    {
        cmd.emplace_back(orient[q], x1, y1);
        return;
    }
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    int l2 = l / 2;
    switch (q)
    {
    case 1:
    {
        solve(l2, xm + 1, x2, y1, ym, x, y);
        solve(l2, x1, xm, y1, ym, xm, ym);
        solve(l2, x1, xm, ym + 1, y2, xm, ym + 1);
        solve(l2, xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
        cmd.emplace_back(orient[1], xm, ym);
        break;
    }
    case 2:
    {
        solve(l2, xm + 1, x2, y1, ym, xm + 1, ym);
        solve(l2, x1, xm, y1, ym, x, y);
        solve(l2, x1, xm, ym + 1, y2, xm, ym + 1);
        solve(l2, xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
        cmd.emplace_back(orient[2], xm, ym);
        break;
    }
    case 3:
    {
        solve(l2, xm + 1, x2, y1, ym, xm + 1, ym);
        solve(l2, x1, xm, y1, ym, xm, ym);
        solve(l2, x1, xm, ym + 1, y2, x, y);
        solve(l2, xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
        cmd.emplace_back(orient[3], xm, ym);
        break;
    }
    case 4:
    {
        solve(l2, xm + 1, x2, y1, ym, xm + 1, ym);
        solve(l2, x1, xm, y1, ym, xm, ym);
        solve(l2, x1, xm, ym + 1, y2, xm, ym + 1);
        solve(l2, xm + 1, x2, ym + 1, y2, x, y);
        cmd.emplace_back(orient[4], xm, ym);
        break;
    }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, x, y;
    cin >> l >> x >> y;
    solve(l, 0, l - 1, 0, l - 1, x, y);
    cout << cmd.size() << '\n';
    for (auto &c : cmd)
    {
        cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << '\n';
    }
}