#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// floor_sum: sum_{i=0}^{n-1} floor((a*i + b) / m)
ull floor_sum(ll n, ll m, ll a, ll b)
{
    ull ans = 0;
    if (a < 0)
    {
        ll a2 = (a % m + m) % m;
        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0)
    {
        ll b2 = (b % m + m) % m;
        ans -= 1ULL * n * ((b2 - b) / m);
        b = b2;
    }

    ull ua = a, ub = b, um = m, un = n;
    while (true)
    {
        if (ua >= um)
        {
            ans += un * (un - 1) / 2 * (ua / um);
            ua %= um;
        }
        if (ub >= um)
        {
            ans += un * (ub / um);
            ub %= um;
        }
        ull y_max = ua * un + ub;
        if (y_max < um)
            break;
        un = y_max / um;
        ub = y_max % um;
        swap(um, ua);
    }
    return ans;
}

void solve()
{
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    ll s1 = floor_sum(N, M, A, B);
    ll s2 = floor_sum(N, M, A - 1, B - 1);
    cout << N - (s1 - s2) << "\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        solve();
}