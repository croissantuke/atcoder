#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    if (S.front() == S.back())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}