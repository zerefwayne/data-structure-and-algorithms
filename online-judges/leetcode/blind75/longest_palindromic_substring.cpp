#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindromeBrute(string s)
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

    string preprocess(string str)
    {

        int n = str.length();

        string converted = "$#";

        for (auto &c : str)
        {
            converted.push_back(c);
            converted.push_back('#');
        }

        converted.push_back('@');

        return converted;
    }

    string manachers(string original, string str)
    {

        int n = str.length();
        vector<int> p(n, 0);

        int C = 0;
        int R = 0;

        for (int i = 1; i < n - 1; i++)
        {

            int mirror = 2 * C - i;

            if (R > i)
            {
                p[i] = min(R - i, p[mirror]);
            }

            while (str[i + (1 + p[i])] == str[i - (1 + p[i])])
            {
                p[i]++;
            }

            if (i + p[i] > R)
            {
                C = i;
                R = i + p[i];
            }
        }

        int length = 0;
        int center = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (p[i] > length)
            {
                length = p[i];
                center = i;
            }
        }

        return original.substr((center - 1 - length) / 2, length);
    }

    string longestPalindrome(string s)
    {

        //Approach 1: Optimized Brute Force (Two Pointer) average N^2 worst N^3 192ms

        // return longestPalindromeBrute(s);

        // Approach 2: Manacher's Algorithm O(n) 8ms runtime & comparable memory

        return manachers(s, preprocess(s));
    }
};