## Approach 1: Recursive Solution O(3^n) TLE

```cpp
int editDistanceUtil(string A, string B, int i, int j) {
    
    if(i == 0) {
        return j;
    }
    
    if(j == 0) {
        return i;
    }
    
    if(A[i-1] == B[j-1]) {
        return editDistanceUtil(A, B, i-1, j-1);
    }
    
    return 1 + min(editDistanceUtil(A, B, i-1, j-1), min(editDistanceUtil(A, B, i-1, j), editDistanceUtil(A, B, i, j-1)));
    
}

int Solution::minDistance(string A, string B) {
    
    return editDistanceUtil(A, B, A.length(), B.length());
    
}
```

## Approach 2: Memoized Approach Time O(n^2)

```cpp
string str(int i, int j)
{
    return to_string(i) + "," + to_string(j);
}

int editDistanceUtil(string A, string B, int i, int j, unordered_map<string, int> &cache)
{

    if (cache.find(str(i, j)) != cache.end())
    {
        return cache[str(i, j)];
    }

    int val;

    if (i == 0)
    {
        val = j;
    }
    else if (j == 0)
    {
        val = i;
    }
    else if (A[i - 1] == B[j - 1])
    {
        val = editDistanceUtil(A, B, i - 1, j - 1, cache);
    }
    else
    {
        val = 1 + min(editDistanceUtil(A, B, i - 1, j - 1, cache), min(editDistanceUtil(A, B, i - 1, j, cache), editDistanceUtil(A, B, i, j - 1, cache)));
    }

    cache[str(i, j)] = val;
    return val;
}

int Solution::minDistance(string A, string B)
{

    int a = A.length();
    int b = B.length();

    unordered_map<string, int> cache;

    return editDistanceUtil(A, B, A.length(), B.length(), cache);
}

```

## Approach 3: Bottom Up Table DP Space O(n^2) Time O(n^2)

```cpp
int Solution::minDistance(string A, string B)
{

    int a = A.length();
    int b = B.length();

    vector<vector<int>> dp(a + 1, vector<int>(b + 1));

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (A[a - 1] == B[b - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[a][b];
}
```

