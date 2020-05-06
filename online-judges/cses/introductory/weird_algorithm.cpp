#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void simulate(lli n)
{

    while (true)
    {
        printf("%lld ", n);

        if (n == 1)
        {
            break;
        }
        else if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }

    printf("\n");
}

void task()
{

    lli n;
    scanf("%lld", &n);

    simulate(n);
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}