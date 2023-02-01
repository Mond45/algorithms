#include <iostream>
#include <vector>

using namespace std;

int *arr, n;

inline int count()
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << count();
    delete[] arr;
}