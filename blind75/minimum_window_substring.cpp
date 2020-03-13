#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        int s_len = s.length();
        int t_len = t.length();

        if (s_len < t_len || s_len == 0 || t_len == 0)
        {
            return "";
        }
        else if (s_len == t_len)
        {
            if (s == t)
            {
                return s;
            }
            else
            {
                return "";
            }
        }

        unordered_map<char, int> c_map;

        for (auto &ch : t)
        {
            c_map[ch]++;
        }

        int count = 0;
        int l = 0;

        int minLength = INT_MAX;
        string minString = "";

        for (int i = 0; i < s_len; i++)
        {

            if (c_map.find(s[i]) != c_map.end())
            {

                if (c_map[s[i]] > 0)
                {
                    count++;
                }
                c_map[s[i]]--;

                while (count == t_len)
                {

                    if (i - l + 1 < minLength)
                    {
                        minLength = i - l + 1;
                        minString = s.substr(l, i - l + 1);
                    }

                    if (c_map.find(s[l]) != c_map.end())
                    {

                        c_map[s[l]]++;
                        if (c_map[s[l]] > 0)
                        {
                            count--;
                        }
                    }

                    l++;
                }
            }
        }

        return minString;
    }
};
