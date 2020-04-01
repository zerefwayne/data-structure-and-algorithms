#include <bits/stdc++.h>

#define lli long long int
#define mod 1000000007

using namespace std;

lli power(lli A, lli N, lli K) {

    lli res = 1;

    while(N) {

        if(N%2 == 0) {

            A = ((A%K) * (A%K))%K;
            N = N/2;

        } else if(N%2 == 1) {

            res = ((res%K) * (A%K))%K;
            N--;

        }

    }

    return res%K;
}

lli GCD(lli A, lli B, lli N) {

    if(A == B) {
        return ( power(A, N, mod) +  power(B, N, mod)) % mod;
    }

    lli candidate = 1;
    lli num = A - B;
    lli temp;

    for(lli i = 1; i*i <= num; i++) {

        if(num % i != 0) {
            continue;
        }

        temp = (power(A, N, i) + power(B, N, i))%i;

        if(temp == 0) candidate = max(candidate, i);

        temp = (power(A, N, num/i) + power(B, N, num/i))%(num/i);

        if(temp == 0) candidate = max(candidate, num/i);


    }

    return candidate % mod;


}

int main() {

    lli t, A, B, N;

    cin>>t;

    while(t--) {
        cin>>A>>B>>N;
        cout<<GCD(A, B, N)<<'\n';
    }

    return 0;

}