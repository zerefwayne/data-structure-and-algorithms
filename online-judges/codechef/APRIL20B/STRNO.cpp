#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
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

void precompute()
{
}

ll primeFactorCount(ll A)
{

    ll count = 0;

    while(A%2 == 0) {
        count++;
        A = A/2;
    }

    for (ll i = 3; i <= sqrt(A); i += 2)
    {
        while (A % i == 0)
        {
            count++;
            A = A / i;
        }
    }

    if(A > 1) {
        count++;
    }

    return count;
}

void task()
{

    ll X, K;
    scanf("%lld %lld", &X, &K);

    ll s = primeFactorCount(X);

    if (s >= K)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

int main()
{

    io;

    int t;
    scanf("%d", &t);

    precompute();

    while (t--)
    {
        task();
    }

    return 0;
}