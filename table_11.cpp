#include <iostream>

using namespace std;

const int N = 1e7 + 5;

// a = number of tables start with col 0 0
// b = number of tables start with col 0 1
// c = number of tables start with col 1 0

int a[2], b[2], c[2];
int cur, pre;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a[0] = b[0] = c[0] = 1;
    cur = 1;
    pre = 0;
    for (int i = 2; i <= n; ++i)
    {
        a[cur] = (a[pre] + b[pre] + c[pre]) % 100000007;
        b[cur] = (a[pre] + c[pre]) % 100000007;
        c[cur] = (a[pre] + b[pre]) % 100000007;
        cur ^= 1;
        pre ^= 1;
    }
    cout << (a[pre] + b[pre] + c[pre]) % 100000007;
}
