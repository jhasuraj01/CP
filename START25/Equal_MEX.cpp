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

    VEC(int) A(N + 1, 0);

    int N2 = N * 2;

    FOR(i, 0, N2) {
        int num; cin >> num;
        ++A[num];
    }

    int left = 0, right = 0;
    vector<bool> AL(N + 1, true), AR(N + 1, true);

    for(int i = 0; i <= N; ++i) {
        if(A[i] == 0) continue;
        if(A[i] & 1) {
            if(left < right) {
                left += (A[i] + 1)/2;
                right += A[i] - (A[i] + 1)/2;

                AL[i] = false;
                if(A[i] - (A[i] + 1)/2) {
                    AR[i] = false;
                }
            }
            else {
                right += (A[i] + 1)/2;
                left += A[i] - (A[i] + 1)/2;

                AR[i] = false;
                if(A[i] - (A[i] + 1)/2) {
                    AL[i] = false;
                }
            }
        }
        else {
            left += A[i]/2;
            right += A[i]/2;
            AR[i] = false;
            AL[i] = false;
        }
    }

    // cout << AL << endl;
    // cout << AR << endl;

    for(int i = 0; i <= N; ++i) {
        if(AR[i] && AL[i]) {
            cout << "YES" << endl;
            return;
        }
        else if(AR[i] || AL[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}