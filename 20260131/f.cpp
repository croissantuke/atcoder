#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
using vi = vector<int>;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    if (!(cin >> N))
        return 0;
    if (N == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    int sz = N * 10;
    vi par(sz + 10, -1);
    queue<int> q;
    rep(i, 1, 10)
    {
        int r = i % N;
        if (r == 0)
        {
            cout << i << "\n";
            return 0;
        }
        int s = r * 10 + i;
        if (par[s] == -1)
        {
            par[s] = -2;
            q.push(s);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int r = u / 10;
        int d = u % 10;
        rep(nx, d, 10)
        {
            int nr = r * 10 + nx;
            if (nr >= N)
                nr %= N;
            if (nr == 0)
            {
                string ans;
                ans += (char)('0' + nx);
                int cur = u;
                while (cur != -2)
                {
                    ans += (char)('0' + (cur % 10));
                    cur = par[cur];
                }
                reverse(all(ans));
                cout << ans << "\n";
                return 0;
            }
            int v = nr * 10 + nx;
            if (par[v] == -1)
            {
                par[v] = u;
                q.push(v);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}