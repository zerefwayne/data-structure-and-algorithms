#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void combinationUtil(vector<vector<int>> &combinations, vector<int> &current, vector<int> &candidates, int num)
    {

        if (num == 0)
        {

            vector<int> newEntry(current.begin(), current.end());

            sort(newEntry.begin(), newEntry.end());

            if (find(combinations.begin(), combinations.end(), newEntry) == combinations.end())
            {
                combinations.emplace_back(newEntry);
            }

            return;
        }

        for (auto &candidate : candidates)
        {

            int diff = num - candidate;

            if (diff >= 0)
            {

                current.emplace_back(candidate);

                this->combinationUtil(combinations, current, candidates, diff);

                current.pop_back();
            }
            else
            {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> combinations;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        this->combinationUtil(combinations, current, candidates, target);

        return combinations;
    }
};