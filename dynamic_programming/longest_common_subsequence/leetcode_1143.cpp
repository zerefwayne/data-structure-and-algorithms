#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int lcs_recursive(string a, string b)
    {

        // Base case

        if (a == "" || b == "")
        {
            return 0;
        }

        // Last character matches

        int len_a = a.length();
        int len_b = b.length();

        if (a[len_a - 1] == b[len_b - 1])
        {
            return 1 + lcs_recursive(a.substr(0, len_a - 1), b.substr(0, len_b - 1));
        }

        return max(lcs_recursive(a, b.substr(0, len_b - 1)), lcs_recursive(a.substr(0, len_a - 1), b));
    }

    int lcs_memoization(string a, string b, unordered_map<string, int> &cache)
    {

        if (a == "" || b == "")
        {
            return 0;
        }

        string key = a + "," + b;

        if (cache.find(key) != cache.end())
        {
            return cache[key];
        }

        int len_a = a.length();
        int len_b = b.length();

        int val;

        if (a[len_a - 1] == b[len_b - 1])
        {
            val = 1 + lcs_memoization(a.substr(0, len_a - 1), b.substr(0, len_b - 1), cache);
        }
        else
        {
            val = max(lcs_memoization(a, b.substr(0, len_b - 1), cache), lcs_memoization(a.substr(0, len_a - 1), b, cache));
        }

        cache[key] = val;

        return val;
    }

    int lcs_bottom_up(string a, string b)
    {

        int len_a = a.length();
        int len_b = b.length();

        if (len_a == 0 || len_b == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1, 0));

        for (int i = 0; i <= len_a; i++)
        {

            for (int j = 0; j <= len_b; j++)
            {

                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len_a][len_b];
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        // Approach 1: Simple recursive code, TLE
        // return lcs_recursive(text1, text2);
        
        // Approach 2: Memoized Top Down Approach, TLE
        // unordered_map<string, int> cache;
        // return lcs_memoization(text1, text2, cache);

        // Approach 3: Bottom up 2D DP Table, Accepted
        return lcs_bottom_up(text1, text2);
    }
};