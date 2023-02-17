#include <iostream>
#include <string>

using namespace std;

bool similar(string_view a, string_view b)
{
    if (a.size() == 1)
        return a == b;
    string_view a1 = a.substr(0, a.size() / 2);
    string_view a2 = a.substr(a.size() / 2, a.size());
    string_view b1 = b.substr(0, b.size() / 2);
    string_view b2 = b.substr(b.size() / 2, b.size());
    return similar(a1, b1) && similar(a2, b2) || similar(a1, b2) && similar(a2, b1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    cout << (similar(s1, s2) ? "YES" : "NO");
}