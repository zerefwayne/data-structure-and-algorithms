```cpp
int Solution::singleNumber(const vector<int> &A)
{
    int res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        res ^= A[i];
    }
    return res;
}
```