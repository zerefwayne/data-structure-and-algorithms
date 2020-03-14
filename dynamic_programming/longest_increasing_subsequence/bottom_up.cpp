#include <bits/stdc++.h>

using namespace std;

class Solution
{

    int lis_bottom_up(vector<int> &nums)
    {

        if (nums.size() < 1)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {

            for (int j = 0; j < i; i++)
            {

                if (nums[j] < nums[i])
                {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(nums.begin(), nums.end());
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return lis_bottom_up(nums);
    }
};