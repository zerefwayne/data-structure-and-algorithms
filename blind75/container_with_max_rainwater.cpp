#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        if (height.size() < 1)
        {
            return 0;
        }

        int max_area = 0;

        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {

            int min_height = min(height[l], height[r]);

            int area = min_height * (r - l + 1);

            max_area = max(max_area, area);

            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return max_area;
    }
};