[Question Link](https://leetcode.com/contest/leetcode-weekly-contest-56/problems/1-bit-and-2-bit-characters/)

## Approach 1 Basic Looping O(n) ACCEPTED

```cpp
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {

        if (bits.size() == 1)
        {
            return true;
        }

        int i = 0;
        int n = bits.size();

        while (i < n)
        {
            if (i == n - 1)
            {
                return true;
            }
            if (bits[i] == 0)
            {
                i++;
            }
            else
            {
                i = i + 2;
            }
        }

        return false;
    }
};
```