#include <bits/stdc++.h>

using namespace std;

void extendedEuclid(int a, int b, int &x, int &y, int &gcd) {
    
    if(b == 0) {
        x = 1;
        y = 0;
        gcd = a;
    } else {
        extendedEuclid(b, a%b, x, y, gcd);
        int temp = x;
        x = y;
        y = temp - floor(a/b)*y;
    }

}

int main() {

    int a = 12;
    int b = 5;

    int gcd;
    int x;
    int y;

    // x is the Modulo inverse when a > b

    extendedEuclid(a, b, x, y, gcd);

    printf("GCD Recursive of %d and %d: %d\n", a, b, gcd);
    printf("Coefficients: x: %d y: %d\n", x, y);
    printf("Modulo inverse of %d under %d is %d\n", a, b, (x%b+b)%b);


}