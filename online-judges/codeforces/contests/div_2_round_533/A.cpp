#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int> sticks(n, 0);

    int sum = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for(int i = 0; i < n; i++) {
        cin>>sticks[i];
        minimum = min(sticks[i], minimum);
        maximum = max(sticks[i], maximum);
    }


    int res = 0;
    int switches = 0;
    int res_t = 0;

    for(int t = minimum; t <= maximum; t++) {
        switches = 0;

        for(int i = 0; i < n; i++) {
            if(sticks[i] != t) {
                switches += abs(sticks[i] - t) - 1;
            }
        }

        
        if(switches < res) {
            res = switches;
            res_t = t;
        }
        
    }

    cout<<res_t<<' '<<res<<'\n';

    return 0;

}