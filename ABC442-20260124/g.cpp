#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// (価値、個数) を価値の昇順に並べた列が与えられる
// 末尾 ofs 個を取り除き、残りを g 個ずつにマージする
// 末尾の価値の総和、およびマージ後の (価値、個数) の列を返す
pair<ll, vector<pair<ll, ll>>> merge(vector<pair<ll, ll>> ls, int ofs, int g)
{
    ll top = 0;
    while (ofs and !ls.empty())
    {
        auto [v, k] = ls.back();
        if (k > ofs)
        {
            top += v * ofs;
            ls.back().second -= ofs;
            break;
        }
        top += v * k;
        ofs -= k;
        ls.pop_back();
    }
    vector<pair<ll, ll>> res;
    ll cnt = 0, sum = 0;
    while (!ls.empty())
    {
        auto [v, k] = ls.back();
        ls.pop_back();
        if (cnt)
        {
            if (cnt + k < g)
            {
                cnt += k;
                sum += v * k;
                continue;
            }
            k -= g - cnt;
            sum += v * (g - cnt);
            res.emplace_back(sum, 1);
            cnt = sum = 0;
        }
        if (k >= g)
        {
            res.emplace_back(v * g, k / g);
        }
        cnt = k % g;
        sum = v * cnt;
    }
    return {top, res};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll c;
    cin >> n >> c;
    vector<vector<pair<ll, ll>>> ls(4);
    for (int i = 0; i < n; i++)
    {
        ll w, v, k;
        cin >> w >> v >> k;
        ls[w].emplace_back(v, k);
    }
    for (int w = 1; w <= 3; w++)
    {
        sort(ls[w].begin(), ls[w].end());
    }
    ll ans = 0;
    for (int p = 0; p < 6; p++)
    {
        auto [t1, g1] = merge(ls[1], p, 6);
        for (int q = 0; q < 3; q++)
        {
            auto [t2, g2] = merge(ls[2], q, 3);
            for (int r = 0; r < 2; r++)
            {
                auto [t3, g3] = merge(ls[3], r, 2);
                ll rem = c - p - q * 2 - r * 3;
                if (rem < 0)
                    continue;
                rem /= 6;
                ll now = t1 + t2 + t3;
                auto g = g1;
                g.insert(g.end(), g2.begin(), g2.end());
                g.insert(g.end(), g3.begin(), g3.end());
                sort(g.begin(), g.end());
                while (!g.empty())
                {
                    auto [v, k] = g.back();
                    if (k >= rem)
                    {
                        now += v * rem;
                        break;
                    }
                    rem -= k;
                    now += v * k;
                    g.pop_back();
                }
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
}
