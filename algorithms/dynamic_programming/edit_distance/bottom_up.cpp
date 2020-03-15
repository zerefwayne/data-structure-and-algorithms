#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

class Solution
{
public:
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

                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {

                    dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceBottomUp(word1, word2);
    }
};