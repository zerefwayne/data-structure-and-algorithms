```cpp
int Solution::trap(const vector<int> &A)
{

    stack<int> heights;
    int water = 0;

    vector<int> left(A.size());
    vector<int> right(A.size());

    int n = A.size();

    left[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(A[i], left[i - 1]);
    }

    right[n - 1] = A[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - A[i];
    }

    return water;
}
```