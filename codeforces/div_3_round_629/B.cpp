#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    int n;
    int k;

    while (t--)
    {

        cin >> n;
        cin >> k;

        int x = 0;
        int sum = 0;

        while (sum < k)
        {
            x++;
            sum = (x * (x + 1)) / 2;
        }

        int one_loc = x - ((sum - k) + 1);

        string resvec(n, 'a');

        resvec[n - x - 1] = 'b';
        resvec[n - one_loc - 1] = 'b';

        cout << resvec << '\n';
    }

    return 0;
}