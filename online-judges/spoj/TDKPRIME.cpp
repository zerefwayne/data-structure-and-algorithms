#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long int li;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;

#define mod 1000000007

#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define pi(a) printf("%d\n", a)
#define all(c) c.begin(), c.end()
#define pb push_back

template <typename T>
T gcd(T a, T b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template <typename T>
T mod_exp(T b, T p, T m)
{
    T x = 1;
    while (p)
    {
        if (p & 1)
            x = (x * b) % m;
        b = (b * b) % m;
        p = p >> 1;
    }
    return x;
}
template <typename T>
T invFermat(T a, T p) { return mod_exp(a, p - 2, p); }
template <typename T>
T exp(T b, T p)
{
    T x = 1;
    while (p)
    {
        if (p & 1)
            x = (x * b);
        b = (b * b);
        p = p >> 1;
    }
    return x;
}

const int limit = 87000008;

bool sieve[limit + 1];
vi primes;

void precompute()
{

    sieve[0] = true;
    sieve[1] = true;

    for (int i = 2; i * i <= limit; i++)
    {
        if (sieve[i] == false)
        {
            for (int j = i * i; j <= limit; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    for (int i = 2; i <= limit; i++)
    {
        if (sieve[i] == false)
        {
            primes.pb(i);
        }
    }
}

void task()
{
    int k;
    scanf("%d", &k);
    printf("%d\n", primes[k - 1]);
}

int main()
{
    io;
    
    int t;
    cin >> t;

    precompute();

    while (t--)
    {
        task();
    }

    return 0;
}