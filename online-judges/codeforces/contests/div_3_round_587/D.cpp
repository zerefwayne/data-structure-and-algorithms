#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{

    int n;
    cin >> n;
    vector<lli> a(n, 0);
    lli gcd = 0;
    lli maxi = INT_MIN;
    lli sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += maxi - a[i];
        gcd = __gcd(gcd, maxi - a[i]);
    }

    lli y = gcd;
    lli z = sum / gcd;

    cout << z << ' ' << y << '\n';

    return 0;
}