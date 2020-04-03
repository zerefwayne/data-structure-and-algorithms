#include <bits/stdc++.h>

#define lli long long int
#define pii pair<int, int>
#define li long int
#define mod 1000000007

using namespace std;

void precompute()
{
}

bool isPrime(int n)
{

    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void task()
{

    int n;
    cin >> n;

    if (isPrime(n))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    cout << '\n';
}

int main()
{

    int t;
    cin >> t;

    precompute();

    while (t--)
    {
        task();
    }

    return 0;
}