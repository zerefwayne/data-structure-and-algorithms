## Approach 1: Uses Largest Rectangle in Histogram O(n^2logn)

```cpp
int largestRectangleInHistogram(vector<int> &A)
{
    stack<int> indexes;
    int max_area = INT_MIN;
    int area;
    int top;
    int i;

    for (i = 0; i < A.size();)
    {
        if (indexes.empty() || A[i] >= A[indexes.top()])
        {
            indexes.push(i++);
        }
        else
        {
            top = indexes.top();
            indexes.pop();
            if (indexes.empty())
            {
                area = A[top] * i;
            }
            else
            {
                area = A[top] * (i - indexes.top() - 1);
            }
            max_area = max(area, max_area);
        }
    }
    while (!indexes.empty())
    {
        top = indexes.top();
        indexes.pop();
        if (indexes.empty())
        {
            area = A[top] * i;
        }
        else
        {
            area = A[top] * (i - indexes.top() - 1);
        }
        max_area = max(area, max_area);
    }
    return max_area;
}

int Solution::solve(vector<vector<int>> &A)
{

    int rows = A.size();
    int cols = A[0].size();
    int max_area = INT_MIN;
    int area;

    if (rows == 0)
    {
        return 0;
    }

    vector<int> sumTillRow(cols);
    vector<int> temp(cols);

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (A[row][col] == 0)
            {
                sumTillRow[col] = 0;
            }
            else
            {
                sumTillRow[col]++;
            }
        }

        temp = sumTillRow;
        sort(temp.begin(), temp.end());
        area = largestRectangleInHistogram(temp);
        max_area = max(area, max_area);
    }

    return max_area;
}
```