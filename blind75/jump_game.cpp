#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = nums.size();

        if (n < 2)
        {
            return true;
        }

        int max_reachable = nums[0];

        for (int i = 0; i < n - 1; i++)
        {

            if (i > 0 && i > max_reachable)
            {
                return false;
            }

            max_reachable = max(max_reachable, i + nums[i]);

            if (max_reachable >= n - 1)
            {
                return true;
            }
        }

        return false;
    }
};