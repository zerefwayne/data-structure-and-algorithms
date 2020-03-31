## Approach 1 use dx and dy and run loop until A^2

```cpp
vector<vector<int>> Solution::generateMatrix(int A)
{
    int limit = A * A;
    int top = 0;
    int bottom = A - 1;
    int left = -1; // It lags by 1
    int right = A - 1;
    vector<vector<int>> res(A, vector<int>(A));
    int dy = 1;
    int dx = 0;
    int counter = 1;
    int x = 0;
    int y = 0;
    bool start = true;

    while (counter <= limit)
    {

        res[x][y] = counter;

        if (x == top && y == right)
        {
            dy = 0;
            dx = 1;
            left++;
        }
        else if (x == bottom && y == right)
        {
            dy = -1;
            dx = 0;
            top++;
        }
        else if (x == bottom && y == left)
        {
            dy = 0;
            dx = -1;
            right--;
        }
        else if (x == top && y == left)
        {
            dy = 1;
            dx = 0;
            bottom--;
        }

        x += dx;
        y += dy;
        counter++;
    }

    return res;
}
```