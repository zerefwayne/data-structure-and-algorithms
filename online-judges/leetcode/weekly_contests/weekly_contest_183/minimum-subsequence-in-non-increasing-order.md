```cpp
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {

        sort(nums.begin(), nums.end(), greater<int>());

        int sum = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
        }

        int curr = 0;
        int i;

        for (i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            sum -= nums[i];

            cout << i << ' ' << curr << ' ' << sum << '\n';

            if (curr > sum)
            {
                break;
            }
        }
        return vector<int>(nums.begin(), nums.begin() + i + 1);
    }
};
```