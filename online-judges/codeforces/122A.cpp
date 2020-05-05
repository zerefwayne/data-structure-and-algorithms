#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli mod = 1000000007;

bool isLucky(int num)
{

    while (num > 0)
    {

        if (num % 10 != 4 && num % 10 != 7)
        {
            return false;
        }

        num /= 10;
    }

    return true;
}

void task()
{
    int num;
    cin >> num;

    if (isLucky(num))
    {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (isLucky(i) || isLucky(num / i))
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    task();
}