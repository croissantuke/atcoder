#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << count(s.begin(), s.end(), 'i') + count(s.begin(), s.end(), 'j') << '\n';
}
