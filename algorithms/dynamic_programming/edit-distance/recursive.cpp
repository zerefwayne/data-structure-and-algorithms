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

    int minDistance(string word1, string word2)
    {

        return minDistanceRecursive(word1, word2, word1.length(), word2.length());
    }
};