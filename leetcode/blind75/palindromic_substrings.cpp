#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {

        if (s.length() < 2)
        {
            return s.length();
        }

        int counter = 0;

        int n = s.length();

        int i = 0;
        int j = n - 1;

        for (int i = 0; i < n; i++)
        {

            j = n - 1;

            while (i <= j)
            {

                if (s[i] == s[j])
                {

                    int l = i;
                    int r = j;

                    bool flag = true;

                    while (l <= r)
                    {

                        if (s[l] != s[r])
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            l++;
                            r--;
                        }
                    }

                    if (flag)
                    {
                        counter++;
                    }
                }

                j--;
            }
        }

        return counter;
    }
};