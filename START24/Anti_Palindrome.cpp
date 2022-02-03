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
    IN(S, string);

    // if(N & 1) {
    //     cout << "NO" << endl;
    //     return;
    // }

    vector<int> A(26, 0);

    for(char c: S) {
        ++A[c - 'a'];
    }

    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    int i = 0;
    for(int index: order) {
        while(A[index]--)
            S[i++] = 'a' + index;
    }

    reverse(S.begin() + N/2, S.end());

    // cout << S << endl;

    for(int i = 0; i <= N/2; ++i) {
        // cout << S[i] << ", " << S[N-i-1] << endl;
        if(S[i] == S[N - i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    cout << S << endl;
}