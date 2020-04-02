## Approach 1 Take a long long int and check on INT_MAX INT_MIN Boundaries

```cpp
int Solution::reverse(int A)
{
    long long res = 0;
    while (A)
    {
        res = res * 10 + A % 10;
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        A = A / 10;
    }
    return res;
}
```

