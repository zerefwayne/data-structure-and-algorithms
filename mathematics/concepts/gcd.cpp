#include <bits/stdc++.h>

using namespace std;

int gcdRecursive(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcdRecursive(b, a%b);
    }
}

int main() {

    int a = 140;
    int b = 12;

    printf("GCD Recursive of %d and %d: %d\n", a, b, gcdRecursive(a, b));
    printf("GCD Recursive of %d and %d: %d\n", b, a, gcdRecursive(b, a));
    printf("GCD Recursive of %d-%d and %d: %d\n", a, b, b, gcdRecursive(a-b, b));
    printf("GCD Recursive of %d and %d-%d: %d\n", a, b, a, gcdRecursive(a, b-a));
}