## Approach 1 Sieve Memory Exceeded

The problem lies in generating the prime numbers efficiently.

Creating the sieve as a vector of int gives a Memory Limit Exceeded, although it is logically correct.

Solve the issue by replacing int with bool.

```cpp
vector<int> Solution::primesum(int A) {
    
    vector<bool> sieve(A+1, true);
    
    sieve[1] = false;
    sieve[0] = false;
    
    int mul;
    int c;
    
    for(int i = 2; i <= A; i++) {
        
        if(sieve[i] == true) {
        
            for(int j = i*2; j <= A; j+=i) {
                sieve[j] = false;
            }
        
        }
    }

    
    for(int i = 2; i <= A/2; i++) {
        
        if(sieve[i] == true && sieve[A-i] == true) {
            return vector<int> {i, A-i};
        }   
        
    }
    
    return vector<int>();
    
}
```