#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> h[i] >> w[i];

    // ord_h, ord_w : ピースの番号の並び替え
    // h[ord_h[i]] >= h[ord_h[i + 1]]
    // w[ord_w[i]] >= w[ord_w[i + 1]]
    vector<int> ord_h(N), ord_w(N);
    iota(ord_h.begin(), ord_h.end(), 0);
    sort(ord_h.begin(), ord_h.end(), [&](int x, int y)
         { return h[x] > h[y]; });
    iota(ord_w.begin(), ord_w.end(), 0);
    sort(ord_w.begin(), ord_w.end(), [&](int x, int y)
         { return w[x] > w[y]; });

    vector<int> ans_x(N, -1), ans_y(N, -1);
    vector<bool> used(N, false);
    auto ith = ord_h.begin();
    auto itw = ord_w.begin();
    for (int rem = N; rem > 0; rem--)
    {
        // すでに使用済みなら飛ばす
        while (used[*ith])
            ith++;
        while (used[*itw])
            itw++;
        // ピース i が縦 H ブロック or 横 W ブロック
        int i = h[*ith] == H ? *ith : *itw;
        // 右下に置く
        ans_x[i] = H - h[i] + 1;
        ans_y[i] = W - w[i] + 1;
        used[i] = true;
        if (h[i] == H)
        {
            W -= w[i];
        }
        else
        {
            H -= h[i];
        }
    }
    for (int i = 0; i < N; i++)
        cout << ans_x[i] << " " << ans_y[i] << "\n";
}
