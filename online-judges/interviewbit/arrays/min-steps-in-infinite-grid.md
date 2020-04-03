```cpp
int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    if (A.size() < 2)
    {
        return 0;
    }

    int distance = 0;

    for (int i = 1; i < A.size(); i++)
    {
        distance += max(abs(A[i] - A[i - 1]), abs(B[i] - B[i - 1]));
    }

    return distance;
}
```