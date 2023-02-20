#include <iostream>

using namespace std;

int table[100];

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (table[n])
        return table[n];
    return table[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << fib(n);
}