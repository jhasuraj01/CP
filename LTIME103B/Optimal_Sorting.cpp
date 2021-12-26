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

    VEC(long long int) A(N), B(N);

    multiset <long long int> look_up, look_down;

    FOR(i, 0, N) {
        cin >> A[i];
        B[i] = A[i];
    }

    SORT(A);

    int start = 0;
    while (start < N && A[start] == B[start]) { ++start; };

    int end = N - 1;
    while (end > 0 && A[end] == B[end]) { --end; };

    if (start == N)
    {
        cout << 0 << endl;
    }
    else
    {
        int operations = 0;
        
        for (int i = start; i <= end; ++i)
        {
            if (look_up.count(B[i]))
            {
                look_up.erase(look_up.find(B[i]));
            }
            else {
                look_down.insert(B[i]);
            }

            if (look_down.count(A[i]))
            {
                look_down.erase(look_down.find(A[i]));
            }
            else {
                look_up.insert(A[i]);
            }

            if(look_down.empty() && look_up.empty()) {
                operations += A[i] - A[start];
                start = i+1;
            }
        }

        cout << operations << endl;
    }
}

/*
up:  
low: 

1 2 3

B: 1 3 1 2 9 8
A: 1 1 2 3 8 9

1 1 3 2 9 8 => 2



*/