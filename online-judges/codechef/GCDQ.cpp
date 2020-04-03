// https://www.codechef.com/problems/GCDQ

#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n;
    int q;

    while (t--)
    {

        cin >> n >> q;
        vector<int> arr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        vector<int> pre(n+1, 0);
        vector<int> suff(n+2, 0);

        for(int i = 1; i <= n; i++) {
            pre[i] = __gcd(pre[i-1], arr[i]);
        }

        for(int i = n; i >= 1; i--) {
            suff[i] = __gcd(arr[i], suff[i+1]);
        }

        int L;
        int R;

        for (int idx = 0; idx < q; idx++)
        {
            cin >> L >> R;
            cout<<__gcd(pre[L-1], suff[R+1])<<'\n';
        }
    }

    return 0;
}
