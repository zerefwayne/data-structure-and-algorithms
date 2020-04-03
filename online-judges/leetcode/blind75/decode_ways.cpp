#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int dpSize = s.size() + 1;
        int dp[dpSize];
        dp[dpSize - 1] = 1;
        if (s[s.size() - 1] == '0')
        {
            dp[dpSize - 2] = 0;
        }
        else
        {
            dp[dpSize - 2] = 1;
        }
        for (int i = dpSize - 3; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = 1 * dp[i + 1];
                if (stoi(s.substr(i, 2)) < 27 && stoi(s.substr(i, 2)) >= 10)
                {
                    dp[i] = dp[i] + 1 * dp[i + 2];
                }
            }
        }
        return (dp[0]);
    }
};