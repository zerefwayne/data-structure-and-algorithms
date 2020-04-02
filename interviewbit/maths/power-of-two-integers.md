## Approach 1 Check if min power of prime factor is 1 WA

```cpp
int gcdPrimeCount(int A)
{

    int mini_p = 0;

    int count = 0;

    while (A % 2 == 0)
    {
        count++;
        A = A / 2;
    }

    mini_p = count;

    if (mini_p == 1)
    {
        return 1;
    }

    for (int i = 3; i * i <= A; i += 2)
    {

        if (A % i == 0)
        {

            count = 0;

            while (A % i == 0)
            {
                count++;
                A = A / i;
            }

            mini_p = min(mini_p, count);

            if (mini_p == 1)
            {
                return 1;
            }
        }
    }

    return mini_p;
}
```

## Approach 2: Calculate pth roots of the number O(1) AC

```cpp
int utilIsPower(int A)
{

    if (A == 1 || A == 0)
    {
        return 1;
    }
    int power = 2;
    float x = pow(A, 1.0 / power);

    while ((int)x > 1)
    {

        if (x - (int)x == 0)
        {
            return 1;
        }
        power++;
        x = pow(A, 1.0 / power);
    }

    return 0;
}
```

```cpp
int Solution::isPower(int A)
{

    return utilIsPower(A);
}
```

