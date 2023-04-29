#include <iostream>
#include <vector>

using namespace std;

int len[4];
int idx[4];
int cnt[4][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        len[v[i]]++;
    }
    for (int i = 1; i <= 3; ++i)
    {
        idx[i] = idx[i - 1] + len[i];
    }
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = idx[i - 1]; j < idx[i]; ++j)
        {
            cnt[i][v[j]]++;
        }
    }
    int res{};
    for (int i = 1; i <= 3; ++i)
    { // eliminate other numbers from each interval
        for (int j = i + 1; j <= 3; ++j)
        {
            // swap with the correct number first
            int s = min(cnt[i][j], cnt[j][i]);
            cnt[i][j] -= s;
            cnt[j][i] -= s;
            res += s;
            // swap the rest from the other one
            for (int k = i + 1; k <= 3; ++k)
            {
                if (k != j)
                {
                    cnt[k][i] -= cnt[i][j];
                    cnt[k][j] += cnt[i][j];
                    res += cnt[i][j];
                    cnt[i][j] = 0;
                }
            }
        }
    }

    cout << res;
}