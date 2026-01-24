#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x = 0, y = 0;
	int q;
	cin >> q;
	while (q--)
	{
		int a;
		cin >> a;
		if (a == 1)
			x++;
		else if (a == 2 && x > 0)
			x--;
		else if (a == 3)
			y = 1 - y;
		if (x >= 3 && y == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
