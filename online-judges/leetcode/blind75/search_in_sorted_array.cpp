#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r)
        {

            int m = l + (r - l) / 2;

            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        if (nums[l] == target)
        {
            return l;
        }

        int start;
        int end;

        if (l == 0)
        {
            start = 0;
            end = n - 1;
        }
        else if (target > nums[l])
        {
            start = 0;
            end = l - 1;
        }
        else if (nums[l] > target)
        {
            start = l + 1;
            end = n - 1;
        }

        while (l < r)
        {

            int m = l + (r - l) / 2;

            if (target == nums[m])
            {
                return m;
            }
            else if (target < nums[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return -1;
    }
};