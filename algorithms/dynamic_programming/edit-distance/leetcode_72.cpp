#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

class Solution
{
public:
    int minDistanceRecursive(string word1, string word2, int i, int j)
    {

        if (i == 0)
        {
            return j;
        }

        if (j == 0)
        {
            return i;
        }

        if (word1[i - 1] == word2[j - 1])
        {
            return minDistanceRecursive(word1, word2, i - 1, j - 1);
        }

        return 1 + max({minDistanceRecursive(word1, word2, i - 1, j), minDistanceRecursive(word1, word2, i, j - 1), minDistanceRecursive(word1, word2, i - 1, j - 1)}, comp);
    }

    int minDistanceMemoized(string word1, string word2, int i, int j, unordered_map<string, int> &cache)
    {

        string loc = to_string(i) + "," + to_string(j);

        if (cache.find(loc) != cache.end())
        {
            return cache[loc];
        }

        int val;

        if (i == 0)
        {
            val = j;
        }
        else if (j == 0)
        {
            val = i;
        }
        else if (word1[i - 1] == word2[j - 1])
        {
            val = minDistanceMemoized(word1, word2, i - 1, j - 1, cache);
        }
        else
        {
            val = 1 + max({minDistanceMemoized(word1, word2, i - 1, j, cache), minDistanceMemoized(word1, word2, i, j - 1, cache), minDistanceMemoized(word1, word2, i - 1, j - 1, cache)}, comp);
        }

        cache[loc] = val;

        return val;
    }

    int minDistanceBottomUp(string word1, string word2)
    {

        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++)
        {

            for (int j = 0; j <= len2; j++)
            {

                if (i == 0 || j == 0)
                {
                    dp[i][j] = i == 0 ? j : i;
                    continue;
                }

                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}, comp);
                }
            }
        }

        return dp[len1][len2];
    }

    int minDistance(string word1, string word2)
    {
        // Approach 1: Naive Recursive: TLE
        //      return minDistanceRecursive(word1, word2, word1.length(), word2.length());

        // Approach 2: Memoized Approach: Accepted (164 ms,	94.1 MB)
        //
        //      unordered_map<string, int> cache;
        //      return minDistanceMemoized(word1, word2, word1.length(), word2.length(), cache);

        // Approach 3: Bottom Up Approach: Accepted (12 ms, 10.6 MB)

        return minDistanceBottomUp(word1, word2);
    }
};