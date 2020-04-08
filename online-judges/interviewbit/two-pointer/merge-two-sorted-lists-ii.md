## Approach 1 O(n^2) method

```cpp
void Solution::merge(vector<int> &A, vector<int> &B)
{

    int a = A.size();
    int b = B.size();

    int i = 0;
    int j = 0;

    for (i = 0; i < a; i++)
    {

        if (A[i] > B[j])
        {

            int x = A[i];
            A[i] = B[j];
            B[j] = x;

            int k = j;
            int temp = B[j];

            while (k < b - 1 && temp > B[k + 1])
            {
                B[k] = B[k + 1];
                k++;
            }

            B[k] = temp;
        }
    }

    for (int j = 0; j < b; j++)
    {
        A.emplace_back(B[j]);
    }
}
```

## Approach 2

```cpp
void Solution::merge(vector<int> &A, vector<int> &B)
{

    int a = A.size();
    int b = B.size();

    

    int i = 0;
    int j = 0;

    for (i = 0; i < a; i++)
    {

        if (A[i] > B[j])
        {

            int x = A[i];
            A[i] = B[j];
            B[j] = x;

            if (j < b - 1 && B[j] > B[j + 1])
            {
                j++;
            }

            if()

        }
    }

    int l = 0;
    int r = j;

    while (l < r && r < b)
    {

        if (B[l] <= B[r])
        {
            A.emplace_back(B[l]);
            l++;
        }
        else
        {
            A.emplace_back(B[r]);
            r++;
        }
    }

    while (l < j)
    {
        A.emplace_back(B[l]);
        l++;
    }

    while (r < b)
    {
        A.emplace_back(B[r]);
        r++;
    }
}
```

## Approach 3 Using insert

```cpp
bool checkGreater(int A, int B)
{
    if (A > B)
    {
        return true;
    }
    return false;
}

void Solution::merge(vector<int> &A, vector<int> &B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0, j = 0;
    while ((i < A.size()) && (j < B.size()))
    {
        bool a = checkGreater(A[i], B[j]);
        if (a)
        {
            A.insert(A.begin() + i, B[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    while (j != B.size())
    {
        A.push_back(B[j]);
        j++;
    }
}
```