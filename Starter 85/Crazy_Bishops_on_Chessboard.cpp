#include <bits/stdc++.h>
using namespace std;

#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

long long pow_s(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long pow_m(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
// string s = bitset<8>(n).to_string();    int to binary string
long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    if (n & 1)
        cout << (3 * n - 5) / 2 << endl;
    else
        cout << (3 * n - 6) / 2 << endl;
}

int32_t main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}