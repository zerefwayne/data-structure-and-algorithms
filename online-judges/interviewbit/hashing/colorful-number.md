```cpp
vector<int> numToDigit(int A)
{

    vector<int> res;

    if (A == 0)
    {
        res.emplace_back(0);
        return res;
    }

    while (A > 0)
    {
        res.emplace_back(A % 10);
        A /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

int Solution::colorful(int A)
{

    vector<int> digits = numToDigit(A);

    unordered_set<int> products;
    int product = 1;

    for (int i = 0; i < digits.size(); i++)
    {

        product = 1;

        for (int j = i; j < digits.size(); j++)
        {

            product *= digits[j];

            if (products.find(product) == products.end())
            {
                products.insert(product);
            }
            else
            {
                return 0;
            }
        }
    }

    return 1;
}
```