#include <iostream>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    long long total = 0;
    long long t = 0;
    for (;;)
    {
        total += N + t;
        if (total >= K)
            break;
        t++;
    }
    cout << t << endl;
}
