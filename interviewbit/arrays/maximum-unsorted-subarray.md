## Approach 1

```cpp
vector<int> Solution::subUnsort(vector<int> &A)
{

    int n = A.size();

    if (n < 2)
    {
        return vector<int>{-1};
    }

    int l = -1;
    int r = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            l = i;
            break;
        }
    }

    if (l == -1)
    {
        return vector<int>{-1};
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (A[i - 1] > A[i])
        {
            r = i;
            break;
        }
    }

    int maxi = A[l];
    int mini = A[l];

    for (int i = l; i <= r; i++)
    {
        maxi = max(A[i], maxi);
        mini = min(A[i], mini);
    }

    for (int i = 0; i < l; i++)
    {
        if (A[i] > mini)
        {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i > r; i--)
    {
        if (A[i] < maxi)
        {
            r = i;
            break;
        }
    }

    return vector<int>{l, r};
}
```