Properties of median and counting numbers smaller than a number in a row in O(log n) using upper_bound

1. Median of any array is >= (1 + number of elements)/2
2. Binary search of an array (upper_bound in C++) can give the number of elements less than the given element
3. Counting elements lesser than a number takes O(log(cols)) time
4. Counting for whole matrix takes O(rows * log(cols)) time

Finding the potential median

1. Find the minimum and maximum element, and do a binary search between range [minimum, maximum]
2. If the number of elements are smaller than the mid element, this means that the median is greater than the mid
3. because we are counting number of elements **smaller** than the current element.

```cpp
int Solution::findMedian(vector<vector<int>> &A)
{
    int rows = A.size();
    int cols = A[0].size();

    int els = rows * cols;

    int min_ele = INT_MAX;
    int max_ele = INT_MIN;

    int i;
    int j;

    for (i = 0; i < rows; i++)
    {
        min_ele = min(A[i][0], min_ele);
        max_ele = max(A[i][cols - 1], max_ele);
    }

    int desired = (1 + els) / 2;
    int curr;
    int count;

    while (min_ele < max_ele)
    {

        curr = min_ele + (max_ele - min_ele) / 2;
        count = 0;

        for (i = 0; i < rows; i++)
        {
            count += upper_bound(A[i].begin(), A[i].end(), curr) - A[i].begin();
        }

        if (count < desired)
        {
            min_ele = curr + 1;
        }
        else
        {
            max_ele = curr;
        }
    }

    return min_ele;
}
```