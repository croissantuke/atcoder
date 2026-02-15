#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> f(n + 1);
    for (int i = n; i >= 1; --i)
    {
        f[i] = (a[i] == i) ? i : f[a[i]];
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << f[i] << (i == n ? "" : " ");
    }
    cout << '\n';

    return 0;
}