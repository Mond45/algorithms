#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    stack<pair<int, int>> s;
    s.emplace(n, 1); //(sum,offset)
    while (!s.empty())
    {
        auto [sum, offset] = s.top();
        s.pop();
        if (!sum)
            cnt++;
        else
        {
            for (int i = offset; i <= n; ++i)
            {
                if (sum < i)
                    break;
                s.emplace(sum - i, i);
            }
        }
    }
    cout << cnt;
}
