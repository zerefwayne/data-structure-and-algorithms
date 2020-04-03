[https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/)

## Approach 1: XOR of all numbers gives the single element which doesn't repeat

```cpp
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (auto num : nums)
        {
            res = res ^ num;
        }
        return res;
    }
};
```