#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{

    ll t;
    cin >> t;
    ll n;
    ll k;

    while (t--)
    {

        cin >> n;
        cin >> k;

        ll x = 0;
        ll sum = 0;

        while (sum < k)
        {
            x++;
            sum = (x * (x + 1)) / 2;
        }

        ll one_loc = x - ((sum - k) + 1);

        string resvec(n, 'a');

        resvec[n - x - 1] = 'b';
        resvec[n - one_loc - 1] = 'b';

        cout << resvec << '\n';
    }

    return 0;
}