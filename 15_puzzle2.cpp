#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

using state = tuple<int, int, vector<int>, int, int>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int lut[16][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6},
    {1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4, 4, 3, 4, 5},
    {2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3, 5, 4, 3, 4},
    {3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2, 6, 5, 4, 3},
    {1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5},
    {2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4},
    {3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3},
    {4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2},
    {2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4},
    {3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3},
    {4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2},
    {5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1},
    {3, 4, 5, 6, 2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3},
    {4, 3, 4, 5, 3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2},
    {5, 4, 3, 4, 4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1}};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline int heuristic(int depth, const vector<int> &board)
{
    for (int i = 0; i < 16; ++i)
    {
        if (board[i] != 0)
        {
            int cx = (board[i] - 1) % 4, cy = (board[i] - 1) / 4;
            int x = i % 4, y = i / 4;
            depth += abs(cx - x) + abs(cy - y);
        }
    }
    return depth;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> initial(16);
    int x0, y0;
    for (int i = 0; i < 16; ++i)
    {
        cin >> initial[i];
        if (initial[i] == 0)
        {
            x0 = i % 4;
            y0 = i / 4;
        }
    }
    min_heap<state> pq;
    set<vector<int>> set;
    set.emplace(initial);
    pq.emplace(heuristic(0, initial), 0, initial, x0, y0);
    while (!pq.empty())
    {
        auto [cost, depth, board, x, y] = pq.top();
        pq.pop();
        if (depth == cost)
        {
            cout << depth << '\n';
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < 4 && 0 <= ny && ny < 4)
            {
                swap(board[4 * ny + nx], board[4 * y + x]);
                if (set.find(board) == set.end())
                {
                    pq.emplace(heuristic(depth + 1, board), depth + 1, board, nx, ny);
                    set.emplace(board);
                }
                swap(board[4 * ny + nx], board[4 * y + x]);
            }
        }
    }
}