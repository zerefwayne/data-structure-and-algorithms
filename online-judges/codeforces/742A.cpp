#include <bits/stdc++.h>

using namespace std;

int main()
{

    long int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1 << '\n';
        return 0;
    }

    switch (n % 4)
    {
    case 0:
        cout << 6 << '\n';
        break;
    case 1:
        cout << 8 << '\n';
        break;
    case 2:
        cout << 4 << '\n';
        break;
    case 3:
        cout << 2 << '\n';
        break;
    default:
        break;
    }

    return 0;
}