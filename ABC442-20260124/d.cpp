#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), s(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            --x;
            swap(a[x], a[x + 1]);
            s[x + 1] = s[x] + a[x];
        }
        else
        {
            int l, r;
            cin >> l >> r;
            --l;
            cout << s[r] - s[l] << '\n';
        }
    }
}
