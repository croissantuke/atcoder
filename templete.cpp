#include <bits/stdc++.h>
using namespace std;

// 高速化・型定義
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using pii = pair<int, int>;

int main()
{
    fast_io;

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    cout << ans << '\n';

    return 0;
}