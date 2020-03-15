#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        vector<int> res;

        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {

            int sum = nums[l] + nums[r];

            if (sum == target)
            {
                res.emplace_back(l);
                res.emplace_back(r);
                return res;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        res.emplace_back(-1);

        return res;
    }
};