/*
    https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

    Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

    For example, if , it is a valid string because frequencies are . So is  because we can remove one  and have  of each character in the remaining string. If  however, the string is not valid as we can only remove  occurrence of . That would leave character frequencies of .

*/

#include <bits/stdc++.h>

using namespace std;

bool myComparator(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second < b.second;
}

// Complete the isValid function below.
string isValid(string s)
{

    if (s.length() < 2)
    {
        return "YES";
    }

    unordered_map<char, int> countOf;

    for (auto &c : s)
    {
        countOf[c]++;
    }

    vector<pair<char, int>> counts(countOf.begin(), countOf.end());

    sort(counts.begin(), counts.end());

    int n = counts.size();

    if (n == 1)
    {
        return "YES";
    }
    else
    {
        if (counts[0].second == (counts[n - 1].second))
        {
            return "YES";
        }
        if (counts[0].second - 1 == counts[1].second && counts[1].second == counts[n - 1].second)
        {
            return "YES";
        }
        if (counts[n - 1].second == 1 && counts[0].second == counts[n - 2].second)
        {
            return "YES";
        }
    }

    return "NO";
}