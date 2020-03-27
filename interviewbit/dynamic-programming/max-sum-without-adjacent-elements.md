## Approach 1: DP 

```cpp
int Solution::adjacent(vector<vector<int>> &A)
{

    int m = 2;
    int n = A[0].size();

    vector<int> dp(n);

    dp[0] = max(A[0][0], A[1][0]);

    if (n == 1)
    {
        return dp[0];
    }

    dp[1] = max(A[0][1], A[1][1]);

    if (n == 2)
    {
        return max(dp[0], dp[1]);
    }

    dp[2] = dp[0] + max(A[0][2], A[1][2]);

    if (n == 3)
    {
        return max(dp[1], dp[2]);
    }

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(A[0][i], A[1][i]) + max(dp[i - 3], dp[i - 2]);
    }

    return max(dp[n - 1], dp[n - 2]);
}
```

## Approach 2: DP Cute Solution EDITORIAL

dp table is of 2 rows, 1st row represents value when current element is not selected, 2nd when selected

```cpp
int Solution::adjacent(vector<vector<int>> V)
{
    assert(V.size() == 2);
    int N = V[0].size();
    int MAXSUM[N + 1][2];
    memset(MAXSUM, 0, sizeof(MAXSUM));
    int ele = max(V[0][0], V[1][0]);
    MAXSUM[0][1] = ele;
    for (int i = 1; i < N; i++)
    {
        int cur_element = max(V[0][i], V[1][i]);
        MAXSUM[i][0] = max(MAXSUM[i - 1][0], MAXSUM[i - 1][1]);
        MAXSUM[i][1] = cur_element + MAXSUM[i - 1][0];
    }
    return max(MAXSUM[N - 1][0], MAXSUM[N - 1][1]);
}
```