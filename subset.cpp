#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

inline void print(const vector<int> &v)
{
    cout << '{';
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ',';
    }
    cout << "}\n";
}

void gen(int k, int offset = 0)
{
    print(res);
    for (int i = offset; i < k; ++i)
    {
        res.emplace_back(i);
        gen(k, i + 1);
        res.pop_back();
    }
}

int main()
{
    gen(4);
}