## Approach 1: DP & Greedy, Count fibonacci till A and then keep subtracting. O(n) space O(n) time ACCEPTED

```cpp
int Solution::fibsum(int A) {
    
    // 1. Create a vector of fibonacci numbers
    
    vector<int> fibs;
    
    // 1.a Push the first two fibonacci numbers
    fibs.emplace_back(1);
    fibs.emplace_back(1);
    
    int i = 1;
    int new_fib;
    
    while (true) {
        
        
        // 1.b Calculate the next fibonacci number
        new_fib = fibs[i] + fibs[i-1];
        if(new_fib > A) {
            // 1.c If the new fibonacci is greater than A, break out of the loop.
            break;
        } else {
            // 1.c Add the new_fib to the fibonacci numbers
            fibs.emplace_back(new_fib);
            i++;
        }
    }
    
    // 1.d i stores the index of fibonacci number just less than A
    
    // 2. Using the greedy approach, we can subtract fibs[i] from A
    
    int count = 0;
    
    
    while(A > 0) {
        A = A - fibs[i];
        count++;
        
        // 2.a While fibs[i] is greater than A, decrease the i
        while(fibs[i] > A) {
            i--;
        }
    }
    
    return count;
    
}
```
