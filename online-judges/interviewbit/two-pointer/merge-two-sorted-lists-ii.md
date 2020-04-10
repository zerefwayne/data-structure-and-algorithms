## Approach 1 O(m+n) method

```cpp
void Solution::merge(vector<int> &A, vector<int> &B)
{
    int a_size = A.size();
    int b_size = B.size();
    vector<int> res;
    
    int i = 0; 
    int j = 0;

    
    while(i < A.size() && j < B.size()) {
        
        if(A[i] <= B[j]) {
            res.push_back(A[i]);
            i++;
        } else {
            res.push_back(B[j]);
            j++;
        }
        
    }
    
    while(i < A.size()) {
            res.push_back(A[i]);
            i++;
    }
    
    while(j < B.size()) {
            res.push_back(B[j]);
            j++;
    }
    
    A = res;
    
    
    
    
}
```