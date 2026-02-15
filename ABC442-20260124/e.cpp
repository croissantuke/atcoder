#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point
{
    int x, y;
};

ll cross(const point &a, const point &b)
{
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

bool cmp(const point &a, const point &b)
{
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh)
        return ah < bh;
    return cross(a, b) > 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<point> pt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pt[i].x >> pt[i].y;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j)
         { return cmp(pt[i], pt[j]); });
    reverse(ord.begin(), ord.end());
    vector<int> rev(n);
    for (int i = 0; i < n; i++)
    {
        rev[ord[i]] = i;
    }
    vector<int> l(n), r(n);
    l[0] = 0, r[n - 1] = n;
    for (int i = 1; i < n; i++)
    {
        l[i] = (cmp(pt[ord[i]], pt[ord[i - 1]]) ? i : l[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = (cmp(pt[ord[i + 1]], pt[ord[i]]) ? i + 1 : r[i + 1]);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        a = l[rev[a]];
        b = r[rev[b]];
        if (a < b)
            cout << b - a << '\n';
        else
            cout << n - a + b << '\n';
    }
}
