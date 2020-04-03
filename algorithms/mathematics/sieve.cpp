#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int N)
{

    vector<bool> arr(N + 1, true);
    vector<int> primes;

    arr[0] = false;
    arr[1] = false;

    for (int i = 2; i*i <= N; i++)
    {

        if (arr[i] == true)
        {

            primes.emplace_back(i);

            for (int j = i * i; j <= N; j += i)
            {

                arr[j] = false;
            }
        }
    }

    return primes;
}

int main()
{

    int N = 100;

    vector<int> primes = sieve(N);
    printf("Primes till %d are:\n\n", N);
    for(auto &prime: primes) {
        printf("%d ", prime);
    }
    cout<<'\n';

    return 0;
}