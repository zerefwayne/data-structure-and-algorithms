```cpp
vector<vector<int>> Solution::prettyPrint(int A)
{

    int n = A;

    int rows = 2 * n - 1;
    int cols = 2 * n - 1;

    vector<vector<int>> res(rows, vector<int>(cols));

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int val = A;

    while (val > 0)
    {

        for (int c = left; c <= right; c++)
        {
            res[top][c] = val;
        }

        top++;

        for (int r = top; r <= bottom; r++)
        {
            res[r][right] = val;
        }

        right--;

        for (int c = right; c >= left; c--)
        {
            res[bottom][c] = val;
        }

        bottom--;

        for (int r = bottom; r >= top; r--)
        {
            res[r][left] = val;
        }

        left++;

        val--;
    }

    return res;
}
```