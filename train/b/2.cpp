#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int h1;
    cin >> h1;

    int result = -1;
    for (int i = 2; i <= n; i++)
    {
        int h;
        cin >> h;
        if (h > h1 && result == -1)
        {
            result = i;
        }
    }

    cout << result << endl;
}