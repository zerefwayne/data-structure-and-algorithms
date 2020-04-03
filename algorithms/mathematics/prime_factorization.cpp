#include <bits/stdc++.h>

using namespace std;

vector<int> primeFactorization(int n)
{

    vector<int> res;
    

    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            res.emplace_back(i);
            n /= i;
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> pf = primeFactorization(20);

    for(auto n: pf) {
        cout<<n<<' ';
    }

    cout<<'\n';

    return 0;
}