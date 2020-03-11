#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        string longest = "";
        int longest_len = 0;

        int len = s.length();

        for (int i = 0; i < len - longest_len; i++)
        {

            int j = len - 1;

            while (j >= i + longest_len)
            {

                if (s[i] == s[j])
                {

                    int l = i;
                    int r = j;

                    bool isPalindrome = true;

                    while (l <= r)
                    {

                        if (s[l] == s[r])
                        {
                            l++;
                            r--;
                        }
                        else
                        {
                            isPalindrome = false;
                            break;
                        }
                    }

                    if (isPalindrome)
                    {
                        if (j - i + 1 > longest.length())
                        {
                            longest = s.substr(i, j - i + 1);
                            longest_len = j - i + 1;
                        }
                    }
                }

                j--;
            }
        }

        return longest;
    }
};