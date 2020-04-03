## Approach 1 Mod combinations Time O(n) Space O(1)

```cpp
int Solution::maxArr(vector<int> &A)
{
    assert(!A.empty());
    int sum = INT_MIN, max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (auto i = 0; i < A.size(); ++i)
    {
        max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min1 = min(min1, A[i] + i);
        min2 = min(min2, A[i] - i);
    }
    sum = max(max1 - min1, max2 - min2);
    return sum;
}
```