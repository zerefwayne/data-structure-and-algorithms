```cpp
bool isVowel(char a)
{

    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int mod = 10003;

int Solution::solve(string A)
{

    int substrings = 0;

    for (int i = 0; i < A.length(); i++)
    {

        if (isVowel(A[i]))
        {
            substrings = (substrings % mod + A.length() % mod - i % mod) % mod;
        }
    }

    return substrings % mod;
}
```