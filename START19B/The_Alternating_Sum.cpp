#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector< type > name(size, value)
#define VEC3(name, type, size) vector< type > name(size)
#define VEC2(name, type) vector< type > name
#define VEC(type) vector< type > 
#define SORT(name) sort(name.begin(), name.end())

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    for (auto e : v) os << e << " ";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, pair <T, T> &p)
{
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

// Example: https://www.codechef.com/viewsolution/54414764
long long int const mod = 1e9+7;
long long int inverse_modulo(long long int p, long long int q)
{
    long long int expo = mod - 2;
    while (expo) {
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}
// long long int const inverse = inverse_modulo(1, 4);

void solution();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

void solution() {
    IN(N, int);

    VEC(int) A(N), O((N+1)/2), E(N/2);
    int odd = 1;
    int even = 1;

    int x;

    cin >> O[0] >> E[0];

    FOR(i, 2, N) {
        cin >> x;
        if((i + 1)%2) {
            O[odd] = x + O[odd - 1];
            ++odd;
        }
        else {
            E[even] = x + E[even - 1];
            ++even;
        }
    }

    // cout << O << endl;
    // cout << E << endl;

    int dif = 0;
    int count = numeric_limits<int>::min();

    for (int i = 0; i < E.size(); ++i)
    {
        dif = abs(O[O.size() - i - 1] - E[E.size() - i - 1]);
        count = max(count, dif);
    }

    cout << count + 2 << endl;
}