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

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return lis_recursive(nums, nums.size() - 1);
    }
};