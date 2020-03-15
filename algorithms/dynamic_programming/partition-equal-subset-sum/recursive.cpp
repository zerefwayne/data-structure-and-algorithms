#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartitionRecursive(vector<int> &nums, int index, vector<bool> &isFirstSetMember)
    {

        if (index == nums.size())
        {

            int sum1 = 0;
            int sum2 = 0;

            for (int i = 0; i < nums.size(); i++)
            {

                if (isFirstSetMember[i])
                {
                    sum1 += nums[i];
                }
                else
                {
                    sum2 += nums[i];
                }
            }

            return sum1 == sum2;
        }
        else
        {

            for (int i = index; i < nums.size(); i++)
            {

                isFirstSetMember[i] = true;

                if (canPartitionRecursive(nums, i + 1, isFirstSetMember))
                {
                    return true;
                }

                isFirstSetMember[i] = false;
            }

            return false;
        }
    }

    bool canPartition(vector<int> &nums)
    {

        if (nums.size() < 2)
        {
            return false;
        }

        vector<bool> isFirstSetMember(nums.size(), false);

        return canPartitionRecursive(nums, 0, isFirstSetMember);
    }
};