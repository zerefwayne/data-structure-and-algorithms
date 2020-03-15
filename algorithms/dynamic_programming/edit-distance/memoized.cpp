#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

class Solution
{
public:
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

    int minDistance(string word1, string word2)
    {
        unordered_map<string, int> cache;
        return minDistanceMemoized(word1, word2, word1.length(), word2.length(), cache);
    }
};