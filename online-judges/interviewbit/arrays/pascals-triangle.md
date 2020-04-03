## Approach 1 Fill A 2D Matrix Requires O(n^2) space

```cpp
vector<vector<int> > Solution::solve(int A) {
    
    // Create a square upper triangle matrix
    // For A = 4
    // 1 1 1 1
    // 1 2 3 1
    // 1 3
    // 1
    
    // Now observe that (i, j)th element belongs to the [i+j] row of pascals triangle
    
    vector<vector<int>> square(A, vector<int>(A, 1));
    
    for(int i = 1; i < A; i++) {
        for(int j = 1; j < A-i; j++ ) {
            square[i][j] = square[i-1][j] + square[i][j-1];
        }
    }
    
    vector<vector<int>> res(A);
    
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < A-i; j++) {
            res[i+j].emplace_back(square[i][j]);
        }
    }
    
    return res;
    
}
```

## Approach 2 Directly build the array

```cpp
vector<vector<int> > Solution::generate(int A) {
     
    vector<vector<int>> r(A);

    for (int i = 0; i < A; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    
    return r;

}
```

