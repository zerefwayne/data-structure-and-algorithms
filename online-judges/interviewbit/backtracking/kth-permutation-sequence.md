## Approach 1: Inbuilt next_permutation() C++

```cpp
string vectorToString(vector<int> &A)
{

    string a = "";

    for (auto num : A)
    {
        a += to_string(num);
    }

    return a;
}

string Solution::getPermutation(int A, int B)
{

    vector<int> permutation;

    for (int i = 1; i <= A; i++)
    {
        permutation.push_back(i);
    }

    int k = 0;

    do
    {

        k++;

        if (k == B)
        {
            return vectorToString(permutation);
        }

    } while (next_permutation(permutation.begin(), permutation.end()));

    return "";
}
```