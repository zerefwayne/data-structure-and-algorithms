## Approach 1 Brute Force O(n^2) time O(1) space

## Approach 2 Trie Based Pattern Matching O(n^2) worst O(n) space

## Approach 3 Sort the strings and only check the first and the last O(nlogn) worst O(1) space

```cpp
bool comparator(string &a, string &b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        return a < b;
    }
}

string Solution::longestCommonPrefix(vector<string> &A)
{

    // Sort the strings according to comparator
    sort(A.begin(), A.end(), comparator);

    // We only have to consider the first and the last string
    // They will have the max difference
    string x = A[0];
    string y = A[A.size() - 1];

    if (x == y)
    {
        return x;
    }

    int i = 0;
    int j = 0;
    int x_length = x.length();
    int y_length = y.length();

    // Run the loop
    while (i < x_length && j < y_length)
    {

        if (x[i] != y[j])
        {
            break;
        }
        else
        {
            i++;
            j++;
        }
    }

    return x.substr(0, i);
}
```