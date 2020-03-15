#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        if (nums.size() < 3)
        {
            return res;
        }

        int len = nums.size();

        for (int i = 0; i < len - 2; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1;
            int k = len - 1;

            while (j < k)
            {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {

                    vector<int> new_entry{nums[i], nums[j], nums[k]};

                    res.emplace_back(new_entry);

                    do
                    {
                        j++;
                    } while (j < k && nums[j] == nums[j - 1]);
                    do
                    {
                        k--;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
                else if (sum < 0)
                {

                    do
                    {
                        j++;
                    } while (j < k && nums[j] == nums[j - 1]);
                }
                else
                {
                    do
                    {
                        k--;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }
        }

        return res;
    }
};