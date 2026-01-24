#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> c(n, n - 1);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		c[a - 1]--; c[b - 1]--;
	}
	rep(i, n) {
		ll ans = c[i] * (c[i] - 1) * (c[i] - 2) / 6;
		cout << ans << " \n"[i == n - 1];
	}
}
