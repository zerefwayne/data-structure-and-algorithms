## Approach 1

```cpp
int Solution::largestRectangleArea(vector<int> &A)
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
```