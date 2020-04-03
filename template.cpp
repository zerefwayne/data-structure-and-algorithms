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
