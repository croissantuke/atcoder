#include <bits/stdc++.h>
using namespace std;
#include <atcoder/fenwicktree>

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

    atcoder::fenwick_tree<int> fw(n);
    for (int i = 0; i < n; i++)
    {
        fw.add(i, +a[i]);
    }

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x--;
            fw.add(x, -a[x]);
            fw.add(x + 1, -a[x + 1]);
            swap(a[x], a[x + 1]);
            fw.add(x, +a[x]);
            fw.add(x + 1, +a[x + 1]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << fw.sum(l, r) << '\n';
        }
    }
}
