```cpp
int Solution::maxArea(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;
    int max_area = INT_MIN;
    int area;

    while (i < j)
    {

        if (A[i] <= A[j])
        {
            area = (j - i) * A[i];
            i++;
        }
        else
        {
            area = (j - i) * A[j];
            j--;
        }

        max_area = max(max_area, area);
    }

    return max(0, max_area);
}
```