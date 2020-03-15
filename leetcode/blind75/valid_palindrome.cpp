#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        if (s.length() < 2)
        {
            return true;
        }

        int i = 0;
        int j = s.length() - 1;

        while (i <= j && !isalnum(s[i]))
        {
            i++;
        }

        while (i <= j && !isalnum(s[j]))
        {
            j--;
        }

        while (i <= j)
        {

            cout << i << ' ' << j << '\n';

            if (isalpha(s[i]) && isalpha(s[j]))
            {

                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
            }
            else if (isalpha(s[i]) || isalpha(s[j]))
            {
                return false;
            }

            if (isdigit(s[i]) && isdigit(s[j]))
            {

                if (s[i] != s[j])
                {
                    return false;
                }
            }
            else if (isdigit(s[i]) || isdigit(s[j]))
            {
                return false;
            }

            do
            {
                i++;
            } while (i <= j && !isalnum(s[i]));

            do
            {
                j--;
            } while (i <= j && !isalnum(s[j]));
        }

        return true;
    }
};