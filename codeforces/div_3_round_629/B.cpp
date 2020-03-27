#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    int n;
    int k;

    while(t--) {

        cin>>n;
        cin>>k;

        int x=0;
        int sum=0;

        while(sum < k) {
            x++;
            sum = (x*(x+1)) / 2;
        }

        int one_loc = x - ((sum - k) + 1);

        vector<char> resvec(n, 'a');

        resvec[x] = 'b';
        resvec[one_loc] = 'b';

        reverse(resvec.begin(), resvec.end());

        for (char c: resvec) {
            cout<<c;
        }

        cout<<'\n';
    }

    return 0;
}