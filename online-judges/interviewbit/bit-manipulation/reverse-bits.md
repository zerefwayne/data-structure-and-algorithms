## Approach 1 O(1) time 

```cpp
unsigned int Solution::reverse(unsigned int A) {
 
    unsigned int reverse = 0;
    
    for(int i = 0; i < 32; i++) {
        reverse = (reverse << 1) | ((A >> i) & 1);
    }
    
    return reverse;
    
}
```