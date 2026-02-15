#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAXA = 10000001;

int spf[MAXA];
int m1[MAXA], m2[MAXA], c1[MAXA];

void sieve()
{
    for (int i = 2; i < MAXA; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j < MAXA; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

ll power(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll modInv(ll n)
{
    return power(n, MOD - 2);
}

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> primes;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        int x = A[i];
        while (x > 1)
        {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            if (m1[p] == 0)
                primes.push_back(p);
            if (cnt > m1[p])
            {
                m2[p] = m1[p];
                m1[p] = cnt;
                c1[p] = 1;
            }
            else if (cnt == m1[p])
            {
                c1[p]++;
            }
            else if (cnt > m2[p])
            {
                m2[p] = cnt;
            }
        }
    }

    ll total_lcm = 1;
    for (int p : primes)
    {
        total_lcm = total_lcm * power(p, m1[p]) % MOD;
    }

    for (int i = 0; i < N; i++)
    {
        ll res = total_lcm;
        int x = A[i];
        while (x > 1)
        {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            if (cnt == m1[p] && c1[p] == 1)
            {
                res = res * modInv(power(p, m1[p] - m2[p])) % MOD;
            }
        }
        cout << res << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    for (int p : primes)
    {
        m1[p] = m2[p] = c1[p] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}