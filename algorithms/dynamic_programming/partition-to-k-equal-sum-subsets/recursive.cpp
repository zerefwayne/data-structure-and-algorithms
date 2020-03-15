#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartitionRecursive(vector<int> &nums, int i, int k, int currentSum, int targetSum, vector<bool> &used)
    {

        if (k == 1)
        {
            return true;
        }

        if (currentSum == targetSum)
        {
            return canPartitionRecursive(nums, 0, k - 1, 0, targetSum, used);
        }

        for (; i < nums.size(); i++)
        {

            if (!used[i])
            {

                used[i] = true;

                if (canPartitionRecursive(nums, i + 1, k, currentSum + nums[i], targetSum, used))
                {
                    return true;
                }

                used[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (k == 0 || nums.size() < 1 || sum % k != 0)
        {
            return false;
        }

        int targetSum = sum / k;

        int n = nums.size();

        vector<bool> used(n, false);

        return canPartitionRecursive(nums, 0, k, 0, targetSum, used);
    }
};