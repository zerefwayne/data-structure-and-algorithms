```cpp
int Solution::titleToNumber(string A)
{
    int res = 0;
    int power = 1;
    for (int i = A.length() - 1; i >= 0; i--)
    {
        res += (A[i] - 'A' + 1) * (power);
        power *= 26;
    }
    return res;
}
```