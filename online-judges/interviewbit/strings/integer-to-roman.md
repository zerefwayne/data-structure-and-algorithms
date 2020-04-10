## Approach 1

```cpp
string printRoman(int number)
{
    string res = "";
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (number > 0)
    {

        int div = number / num[i];
        number = number % num[i];

        while (div--)
        {
            res += sym[i];
        }

        i--;
    }

    return res;
}

string Solution::intToRoman(int A)
{
    return printRoman(A);
}
```

## Approach 2

```cpp
string intToRoman(int num)
{
    // 1000, 2000, 3000
    string M[] = {"", "M", "MM", "MMM"};
    // 100, 200, 300, .. 900
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    // 10, 20, ... 90
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    // 1, 2, ... 9
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
}
```