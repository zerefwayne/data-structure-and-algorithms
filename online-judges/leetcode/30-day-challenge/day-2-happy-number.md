[https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/)

## Approach 1 Insert numbers into a set, if repeats it will form a cycle

## Approach 2 Passed because weak test cases

```cpp
class Solution
{
public:
    bool isHappy(int n)
    {

        int A = n;

        int sum = n;
        int counter = 0;

        for (int i = 0; i < 100; i++)
        {

            n = sum;
            sum = 0;

            while (n)
            {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (sum == 1)
            {
                return true;
            }
        }

        return false;
    }
};
```