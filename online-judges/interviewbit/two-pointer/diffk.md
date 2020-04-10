```cpp
int Solution::diffPossible(vector<int> &A, int B)
{
    int i = 0;
    int j = 0;

    while (i < A.size() && j < A.size())
    {

        if(i == j) {
            j++;
            continue;
        }

        int diff = abs(A[j] - A[i]);

        if (diff == B)
        {
            return 1;
        }
        else if (diff < B)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return 0;
}
```