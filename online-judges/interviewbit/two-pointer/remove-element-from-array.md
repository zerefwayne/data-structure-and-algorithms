```cpp
int Solution::removeElement(vector<int> &A, int B)
{

    int l = 0;
    int r = 0;

    while (r < A.size())
    {

        if (A[r] != B)
        {
            A[l] = A[r];
            l++;
        }

        r++;
    }

    A = vector<int>(A.begin(), A.begin() + l);

    return l;
}
```