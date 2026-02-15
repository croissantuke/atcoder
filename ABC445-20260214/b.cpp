#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    int m = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        m = max(m, (int)S[i].length());
    }
    for (int i = 0; i < N; i++)
    {
        int len = S[i].length();
        int k = (m - len) / 2;
        string T = string(k, '.') + S[i] + string(k, '.');
        cout << T << "\n";
    }
}