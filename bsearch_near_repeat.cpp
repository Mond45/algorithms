#include <iostream>
#include <vector>

using namespace std;

int *arr, n, m;

int search(int val, int l, int r, int idx = -1)
{
    int mid = (l + r) / 2;
    if (l > r)
        return (idx);
    else if (arr[mid] <= val) // search right side
        return search(val, mid + 1, r, mid);
    else if (arr[mid] > val) // search left side
        return search(val, l, mid - 1, idx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    arr = new int[n];
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
    delete[] arr;
}