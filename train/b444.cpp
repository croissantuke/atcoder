#include <bits/stdc++.h>
using namespace std;

int digitsum(int x)
{
    string s = to_string(x);
    int ans = 0;
    for (char c : s)
        ans += c - '0';
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (digitsum(i) == k)
            ans++;

    cout << ans << endl;
}
