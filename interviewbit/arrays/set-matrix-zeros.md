## Approach 1 Use last row and last column as setRowZero boolean values

```cpp
void Solution::setZeroes(vector<vector<int>> &A)
{

    int m = A.size();
    int n = A[0].size();

    int last_col = 1;
    int last_row = 1;

    for (int i = 0; i < m; i++)
    {
        if (A[i][n - 1] == 0)
        {
            last_col = 0;
            break;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (A[m - 1][j] == 0)
        {
            last_row = 0;
            break;
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[i][j] == 0)
            {
                A[m - 1][j] = 0;
                A[i][n - 1] = 0;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[i][n - 1] == 0 || A[m - 1][j] == 0)
            {

                A[i][j] = 0;
            }
        }
    }

    if (last_col == 0)
    {
        for (int i = 0; i < m; i++)
        {
            A[i][n - 1] = last_col;
        }
    }

    if (last_row == 0)
    {
        for (int j = 0; j < n; j++)
        {
            A[m - 1][j] = last_row;
        }
    }
}
```