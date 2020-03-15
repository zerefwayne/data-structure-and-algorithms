#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {

        unordered_map<int, int> countOf;

        for (auto &num : nums)
        {
            countOf[num]++;
        }

        vector<pii> res(countOf.begin(), countOf.end());

        sort(res.begin(), res.end());

        vector<int> count(res.size(), 0);

        for (int i = 1; i < res.size(); i++)
        {
            count[i] = count[i - 1] + res[i - 1].second;
        }

        for (int i = 0; i < res.size(); i++)
        {
            res[i].second = count[i];
        }

        unordered_map<int, int> newCountOf(res.begin(), res.end());

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = newCountOf[nums[i]];
        }

        return ans;
    }
};