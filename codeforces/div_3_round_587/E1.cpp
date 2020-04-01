#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main() {

    lli k;
    int q;

    cin>>q;

    while(q--) {

        cin>>k;

        lli sum = 0;
        lli last = 0;
        lli block = 1;
        
        while (sum < k) {

            block++; 
            last = sum;
            sum = block*(block + 1)/2;
            int t = block;
            while(t) {
                sum += (t/10) * (((t%10+1)*(t%10+2))/2);
                t = t/10;
            } 

        }

        

    }

    return 0;

}