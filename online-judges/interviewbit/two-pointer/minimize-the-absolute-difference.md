```cpp
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{

    int i = 0;
    int j = 0;
    int k = 0;

    int min_diff = INT_MAX;
    int diff;

    while (i < A.size() && j < B.size() && k < C.size())
    {

        diff = abs(max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k])));
        min_diff = min(diff, min_diff);

        int min_el = min(A[i], min(B[j], C[k]));

        if (A[i] == min_el)
        {
            i++;
        }
        else if (B[j] == min_el)
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    return min_diff;
}
```