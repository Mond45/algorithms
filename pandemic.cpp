#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<pair<int, int>> infected;
int r, c;

int solve(int t)
{
    int res = infected.size();
    for (int i = 0; i < t; ++i)
    {
        vector<pair<int, int>> tmp;
        for (auto [x, y] : infected)
        {
            for (auto [dx, dy] : neighbors)
            {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] == 0)
                {
                    res++;
                    map[nx][ny] = 1;
                    tmp.emplace_back(nx, ny);
                }
            }
        }
        infected.insert(infected.end(), tmp.begin(), tmp.end());
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> r >> c >> t;
    map.assign(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                infected.emplace_back(i, j);
            }
        }
    }
    cout << solve(t);
}