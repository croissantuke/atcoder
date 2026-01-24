#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    atcoder::segtree<int, op, e> seg(a);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x--;
            swap(a[x], a[x + 1]);
            seg.set(x, a[x]);
            seg.set(x + 1, a[x + 1]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << '\n';
        }
    }
}
