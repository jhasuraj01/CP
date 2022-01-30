#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
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

long long binpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solution();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

long long flipbits(long long num, int size) {
    long long ans = 0;

    for(int i = 0; i < size; ++i) {
        if(((num >> i) & 1ll) == 0) {
            ans |= (1ll << i);
        }
    }

    return ans;
}

long long xor_sum(long long low, long long high) {
    long long ans = 0;

    int bits = 0;
    while(high >> bits) {
        ++bits;
    }

    for(int i = low; i <= high; ++i) {
        long long res = flipbits(i, bits);

        if (res > high) {
            cout << "It's There";
        }

        if (res == 0ll) res = high;

        ans += (i ^ res);
    }
    return ans;
}

void solution() {
    IN(N, long long int);

    int bits = 0;

    long long int ans = 0;

    while(N > 1) {
        int bits = 0;
        while(N >> bits) {
            ++bits;
        }
        long long low = flipbits(N, bits);
        if(low == 0ll) low = 1ll;
        ans += xor_sum(low, N);
        N = low - 1ll;
    }

    cout << ans << endl;
}