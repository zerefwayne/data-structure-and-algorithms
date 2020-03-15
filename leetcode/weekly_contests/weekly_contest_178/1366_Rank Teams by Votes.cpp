#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<char, vector<int>> &a, pair<char, vector<int>> &b)
{

    int n = a.second.size();

    for (int i = 0; i < n; i++)
    {

        if (a.second[i] != b.second[i])
        {
            return a.second[i] > b.second[i];
        }
    }

    return a.first < b.first;
}

class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {

        unordered_map<char, vector<int>> points;

        for (int i = 0; i < votes[0].length(); i++)
        {
            vector<int> new_entry(votes[0].length(), 0);
            points[votes[0][i]] = new_entry;
        }

        for (auto &vote : votes)
        {
            for (int i = 0; i < vote.length(); i++)
            {
                points[vote[i]][i]++;
            }
        }

        vector<pair<char, vector<int>>> voteCount(points.begin(), points.end());

        sort(voteCount.begin(), voteCount.end(), comparator);

        string ans = "";

        for (auto &count : voteCount)
        {
            ans.push_back(count.first);
        }

        return ans;
    }
};