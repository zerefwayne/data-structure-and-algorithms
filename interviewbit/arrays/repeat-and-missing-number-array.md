## Approach 1 Summation Formulas Time O(n)

```cpp
vector<int> Solution::repeatedNumber(const vector<int> &A)
{

    long long int n = A.size();
    long long int range = (long long int)(n * (n + 1)) / 2;
    long long int actual = 0;
    long long int range_2 = (long long int)(n * (2 * n + 1) * (n + 1)) / 6;
    long long int actual_2 = 0;

    for (auto num : A)
    {
        actual += (long long int)num;
        actual_2 += (long long int)num * (long long int)num;
    }

    long long int aminusb = (long long int)(actual - range);
    long long int aplusb = (long long int)(actual_2 - range_2) / aminusb;

    long long int mis = (aplusb - aminusb) / 2;
    long long int rep = (aplusb + aminusb) / 2;

    return vector<int>{int(rep), int(mis)};
}
```