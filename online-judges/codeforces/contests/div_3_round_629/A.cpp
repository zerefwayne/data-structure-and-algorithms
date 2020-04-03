#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    int a;
    int b;

    while(t--) {
        cin>>a>>b;

        if(a <= b) {
            cout<< b-a<<'\n';
        } else {

        if(a % b == 0) {
            cout<<0<<'\n';
        } else {
            cout<< b - (a%b) << '\n';
        }
        }
    }

    return 0;

}