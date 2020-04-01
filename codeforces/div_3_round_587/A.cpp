#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin>>s;

    int a = 0;
    int b = 0;
    int ops = 0;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'a')
        {
            a++;
        }
        else
        {
            b++;
        }

        if (i % 2 != 0 && a != b)
        {
            if(a > b) {
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }

            ops += abs(a - b) / 2;
            int t = max(a, b) - 1;
            a = t;
            b = t;
        }
    }

    cout << ops << '\n'
         << s << '\n';

    return 0;
}