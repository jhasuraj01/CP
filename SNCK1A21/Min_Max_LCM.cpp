#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    ll T, X, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> X >> K;
        cout << lcm(X, X*2) << " " << lcm(X*K, X*K - 1) << "\n";
    }

    return 0;
}