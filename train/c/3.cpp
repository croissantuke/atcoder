#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++)
        cin >> S[i] >> T[i];

    bool res = true;
    for (int i = 0; i < N; i++)
    {
        bool okS = true;
        for (int j = 0; j < N; j++)
        {
            if (j == i)
                continue;
            if (S[j] == S[i] || T[j] == S[i])
                okS = false;
        }
        bool okT = true;
        for (int j = 0; j < N; j++)
        {
            if (j == i)
                continue;
            if (S[j] == T[i] || T[j] == T[i])
                okT = false;
        }
        if (!okS && !okT)
            res = false;
    }
    cout << (res ? "Yes" : "No") << endl;
}