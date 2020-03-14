#include <bits/stdc++.h>

using namespace std;

class Solution
{

    int lis_recusrive(vector<int> &nums, int prev, int current_pos)
    {

        if (current_pos == nums.size())
        {
            return 0;
        }

        int taken = 0;

        if (nums[current_pos] > prev)
        {
            taken = 1 + lis_recusrive(nums, nums[current_pos], current_pos + 1);
        }

        int not_taken = lis_recusrive(nums, prev, current_pos + 1);

        return max(taken, not_taken);
    }

    int lis_recursive(vector<int> &nums, int i)
    {
        return lis_recusrive(nums, INT_MIN, 0);
    }

    int lis_bottom_up(vector<int> &nums)
    {

        if (nums.size() < 1)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {

            for (int j = 0; j < i; j++)
            {

                if (nums[j] < nums[i])
                {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        // Approach 1: Simple recursive code, TLE
        // return lis_recursive(nums, nums.size() - 1);

        // Approach 2: Bottom Up Approach, Accepted
        return lis_bottom_up(nums);
    }
};