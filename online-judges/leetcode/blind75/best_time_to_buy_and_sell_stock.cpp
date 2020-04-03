#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        if (prices.size() < 2)
        {
            return 0;
        }

        int min_till_now = prices[0];
        int max_diff = INT_MIN;

        for (int i = 1; i < prices.size(); i++)
        {

            if (prices[i] < min_till_now)
            {
                min_till_now = min(min_till_now, prices[i]);
            }
            else
            {
                max_diff = max(max_diff, prices[i] - min_till_now);
            }
        }

        return max(0, max_diff);
    }
};