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

void solution() {
    IN(N, int);

    VEC(long long) A(N);

    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int evens = 0;
    int odds = 0;
    int even_sum = 0;
    int odd_sum = 0;

    for(int i = 1; i < N-1; ++i) {
        if(A[i] & 1) {
            ++odds;
            odd_sum += A[i];
        }
        else {
            ++evens;
            even_sum += A[i];
        }
    }

    int operations = even_sum/2 + odd_sum;

    cout << operations << endl;

}