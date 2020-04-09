## Approach 1 Brute Force TLE Time O(n^2)

```cpp
int Solution::findMinXor(vector<int> &A) {
    int min_xor = INT_MAX;
    for(int i = 0; i < A.size() - 1; i++) {
        for(int j = i+1; j < A.size(); j++) {
            min_xor = min(min_xor, A[i]^A[j]);
        }
    }
    return min_xor;
}
```

## Approach 2 Sort the array, Time O(nlogn)

Consecutive numbers have the chance of having same prefix bit pattern.

```cpp
int Solution::findMinXor(vector<int> &A) {
    
    sort(A.begin(), A.end());
    int min_xor = INT_MAX;
    for(int i = 0; i < A.size() - 1; i++) {
        min_xor = min(min_xor, A[i]^A[i+1]);
    }
    return min_xor;
    
}
```