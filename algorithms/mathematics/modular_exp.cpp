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

int main() {

    lli t, A, B, N;

    cout<<power(1034444224, 7666, mod)<<'\n';

    return 0;

}