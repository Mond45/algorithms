#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int search(int val, int l, int r, int res = -1)
{
    int mid = (l + r) / 2;
    if (l > r)
        return res;
    if (arr[mid] == val)
        return val;
    else if (arr[mid] < val) // search right side
        return search(val, mid + 1, r, arr[mid]);
    else if (arr[mid] > val) // search left side
        return search(val, l, mid - 1, res);
}

int main()
{
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    while (m--)
    {
        int v;
        cin >> v;
        cout << search(v, 0, n - 1) << '\n';
    }
}