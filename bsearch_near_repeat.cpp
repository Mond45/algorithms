#include <iostream>
#include <vector>

using namespace std;

int arr[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    while (m--)
    {
        int q;
        cin >> q;
        int l = 0, r = n - 1;
        int a = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (arr[mid] <= q)
            {
                a = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << a << '\n';
    }
}