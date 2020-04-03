#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int r = nums[0];
        int n = nums.size();

        for (int i = 1, imax = r, imin = r; i < n; i++)
        {
            if (nums[i] < 0)
                swap(imax, imin);

            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            r = max(r, imax);
        }

        return r;
    }
};