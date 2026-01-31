#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, T;
    cin >> N >> T;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    long long ans = 0;
    long long start = 0;
    for (long long a : A)
    {
        if (a > start)
        {
            ans += a - start;
            start = a + 100;
        }
    }
    if (start < T)
        ans += T - start;
    cout << ans << "\n";
}
