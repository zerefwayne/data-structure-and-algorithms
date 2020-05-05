#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli mod = 1000000007;

void task()
{

    lli n, m, a;
    cin >> n >> m >> a;

    cout << ((m + a - 1) / a) * ((n + a - 1) / a) << '\n';
}

int main()
{

    task();
}