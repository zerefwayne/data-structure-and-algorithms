## Approach 1: Greedy O(n) ACCEPTED

```cpp
int Solution::canJump(vector<int> &A)
{

    int max_reachable = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (i > max_reachable)
        {
            return 0;
        }

        max_reachable = max(max_reachable, i + A[i]);

        if(max_reachable >= n) {
            return 1;
        }
    }

    return 1;
}
```