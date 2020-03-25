## Approach 1: Two Pointer O(n^2) time O(1) space

```cpp
int Solution::threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    
    int sum = 0;
    int min_diff = INT_MAX;
    int diff;
    
    int n = A.size();
    
    int l, m, r;
    
    int temp;
    
    for(l = 0; l < n-2; l++) {
        
        m = l+1;
        r = n-1;
        
        while(m < r) {
            
            temp = A[l] + A[m] + A[r];
            diff = abs(temp - B);
            
            if(diff == 0) {
                return temp;
            } else {
                if(diff < min_diff) {
                    min_diff = diff;
                    sum = temp;
                }
                
                if(temp > B) {
                    r--;
                } else {
                    m++;
                }
                
            }
            
        }

    }
    
    return sum;
    
}
```