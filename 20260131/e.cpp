#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

void solve()
{
    int N, C;
    if (!(cin >> N >> C))
        return;

    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];

    vector<int> low(N, -1);
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            if (S[i][j] == '#')
                low[j] = i;
        }
    }
    vector<int> dp(N, 0);
    dp[C - 1] = 2;
    vector<int> nxt(N);
    rrep(i, N - 1, 1)
    {
        int r = i - 1;
        fill(nxt.begin(), nxt.end(), 0);
        rep(j, 0, N)
        {
            bool is_clean_col = (low[j] <= r);
            bool is_wall = (S[r][j] == '#');
            if (dp[j])
            {
                if (is_wall)
                {
                    if (dp[j] == 2)
                        nxt[j] = max(nxt[j], 2);
                }
                else
                {
                    nxt[j] = max(nxt[j], dp[j]);
                }
            }
            for (int pj : {j - 1, j + 1})
            {
                if (pj >= 0 && pj < N && dp[pj])
                {
                    if (is_wall)
                    {
                        if (is_clean_col)
                            nxt[j] = max(nxt[j], 2);
                    }
                    else
                    {
                        nxt[j] = max(nxt[j], is_clean_col ? 2 : 1);
                    }
                }
            }
        }
        dp = nxt;
    }
    string ans;
    ans.reserve(N);
    rep(j, 0, N) ans += (dp[j] ? '1' : '0');
    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    if (cin >> T)
    {
        while (T--)
            solve();
    }
}