[Question Link](https://leetcode.com/contest/leetcode-weekly-contest-56/problems/maximum-length-of-repeated-subarray/)

## Approach 1: Brute Force O(n^3) TLE

## Approach 2: Dynamic Programming O(n^2) ACCEPTED

```cpp
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {

        int m = A.size();
        int n = B.size();

        int res = 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (A[i - 1] == B[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        res = max(dp[i][j], res);
                    }
                }
            }
        }

        return res;
    }
};
```