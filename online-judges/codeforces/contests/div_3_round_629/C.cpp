#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string x;
        string a;
        string b;

        int n;
        cin >> n;
        cin >> x;

        int give_zero = 0;

        bool one_in_a = false;
        bool one_in_b = false;

        for (char c : x)
        {

            if (c == '0')
            {
                if(one_in_a && one_in_b) {
                    a.push_back('0');
                    b.push_back('0');
                } else if(!one_in_a && !one_in_b) {
                    a.push_back('1');
                    b.push_back('2');
                } else if(one_in_a && !one_in_b) {

                }
            }
            else if (c == '1')
            {

                if()

                if (give_zero == 0)
                {
                    a.push_back('0');
                    b.push_back('1');
                }
                else
                {
                    a.push_back('1');
                    b.push_back('0');
                }

                give_zero = 1 - give_zero;
            }
            else
            {

                if(a > b) {
                    b.push_back(0);
                    a.push_back
                }

                a.push_back('1');
                b.push_back('1');
                one_in_a = true;
                one_in_b = true;
            }
        }

        cout << a << '\n';
        cout << b << '\n';
    }
}