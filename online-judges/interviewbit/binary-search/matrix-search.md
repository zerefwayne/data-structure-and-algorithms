## Approach 1 Binary search exactly how you would do if this is flattened.

#### Convert 1D to 2D Coordinates

```cpp
int Solution::searchMatrix(vector<vector<int>> &A, int B)
{

    int rows = A.size();
    int cols = A[0].size();

    int l = 0;
    int r = rows * cols - 1;
    int m, mx, my;

    while (l <= r)
    {

        m = l + (r - l) / 2;

        mx = m / cols;
        my = m % cols;

        if (A[mx][my] == B)
        {
            return 1;
        }
        else if (A[mx][my] < B)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return 0;
}
```