#include <vector>
#include <iostream>

using namespace std;

vector<int> combinations;

void gen(int n, int k, int offset = 0)
{
    if (combinations.size() == k)
    {
        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (idx < k && combinations[idx] == i)
            {
                cout << '1';
                idx++;
            }
            else
            {
                cout << '0';
            }
        }
        cout << '\n';
    }
    else
    {
        for (int i = offset; i < n; ++i)
        {
            combinations.push_back(i);
            gen(n, k, i + 1);
            combinations.pop_back();
        }
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    gen(n, k);
}