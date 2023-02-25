#include <iostream>

using namespace std;

enum
{
    a,
    b,
    c,
    d
};

#define STATES 4
int t[STATES][2];
int dp[STATES][10001];
long long states[] = {a, b, c, d};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t[a][0] = a;
    t[a][1] = b;
    t[b][0] = c;
    t[b][1] = b;
    t[c][0] = a;
    t[c][1] = d;
    t[d][0] = d;
    t[d][1] = d;
    dp[a][0] = 1;
    dp[b][0] = 1;
    dp[c][0] = 1;
    dp[d][0] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int s : states)
        {
            dp[s][i] = (dp[t[s][0]][i - 1] + dp[t[s][1]][i - 1]) % 100000007ll;
        }
    }
    cout << dp[a][n];
}