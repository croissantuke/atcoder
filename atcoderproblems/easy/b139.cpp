#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int ans = 0;
    int outlet = 1;
    while (outlet < B)
    {
        --outlet;
        outlet += A;
        ++ans;
    }
    cout << ans << endl;
}