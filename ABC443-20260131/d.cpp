#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> R(N);
        long long sumR = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> R[i];
            sumR += R[i];
        }

        vector<long long> ub = R;
        for (int i = 1; i < N; ++i)
            ub[i] = min(ub[i], ub[i - 1] + 1);
        for (int i = N - 2; i >= 0; --i)
            ub[i] = min(ub[i], ub[i + 1] + 1);

        long long sumUb = 0;
        for (auto v : ub)
            sumUb += v;
        cout << (sumR - sumUb) << '\n';
    }
    return 0;
}
