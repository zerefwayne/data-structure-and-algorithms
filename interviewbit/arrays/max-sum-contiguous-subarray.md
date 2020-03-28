## Approach 1 Kadane's Algorithm time O(n) space O(1) 

```cpp
int Solution::maxSubArray(const vector<int> &A)
{

    int max_sum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sum = max(A[i], sum + A[i]);
        max_sum = max(sum, max_sum);
    }

    return max_sum;
}
```