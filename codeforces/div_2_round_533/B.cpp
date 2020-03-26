#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    int k;
    cin >> n >> k;

    string word;
    cin >> word;

    int i = 0;
    int j = 0;

    

    int res = 0;
    set<int> s;

    while (i < n)
    {

        while ((i - j + 1) <= k && i < n)
        {
            s.insert(word[i]);

            if (s.size() > 1)
            {
                s.clear();
                j = i;
            }
            else
            {
                i++;
            }
        }

        if (i < n)
        {
            res++;
            j = i;
            s.clear();
        }
        else
        {
            if(i - j == k) {
                res++;
            }

            break;
        }
    }

    cout<<res<<'\n';

    return 0;
}