## Approach 1 Count multiples of 5 on each number

```cpp
int multiples(int num, int divisor)
{
    int count = 0;
    while (num % divisor == 0 && num > 0)
    {
        count++;
        num = num / divisor;
    }
    return count;
}

int Solution::trailingZeroes(int A)
{

    int fives = 0;

    for (int i = 1; i <= A; i++)
    {
        fives += multiples(i, 5);
    }

    return fives;
}
```

## Approach 2: Recursive Oneliner

```cpp
int Solution::trailingZeroes(int A)
{
    return (A == 0) ? 0 : A/5 + trailingZeroes(A/5);
}
```