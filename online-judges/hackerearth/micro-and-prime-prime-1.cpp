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

const int MAX = 1e6 + 7;

vector<bool> sieve(MAX, true);
vector<int> primeprimes;

void precompute()
{

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i * i <= MAX; i++)
    {

        if (sieve[i] == true)
        {
            for (int j = i * i; j <= MAX; j += i)
            {

                sieve[j] = false;
            }
        }
    }

    int counter = 0;

    for (int i = 2; i <= MAX; i++)
    {

        if (sieve[i] == true)
        {
            counter++;
        }

        // If the numbers are primeprime, push them into the vector, sorted automatically
        // Is used a set will give a TLE

        if (sieve[counter] == true)
        {
            primeprimes.push_back(i);
        }
    }
}

// Have to use lower_bound and upper_bound instead of counting all the numbers from L to R


void task()
{

    int L, R;
    scanf("%d %d", &L, &R);

    int counter = upper_bound(all(primeprimes), R) - lower_bound(all(primeprimes), L);

    printf("%d\n", counter);
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