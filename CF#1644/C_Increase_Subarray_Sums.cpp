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

int max_subarray_sum(int index, vector<int>&A, int N, int K, int X, vector<vector<int>>& cache) {
    
    if(index >= N) {
        return 0;
    }
    if(cache[index][K] != -1) {
        return cache[index][K];
    }

    int first = A[index] + max_subarray_sum(index + 1, A, N, K, X, cache);
    int second = K > 0 ? (A[index] + X + max_subarray_sum(index + 1, A, N, K - 1, X, cache)) : 0;
    int third = max_subarray_sum(index + 1, A, N, K, X, cache);
    
    cache[index][K] = max({ first, second, third });

    // if(cache[index][K] == first) {
    //     cout << "Selected(" << index << "): ";
    //     cout << A[index] << endl;
    // }
    // else if(cache[index][K] == second && K > 0) {
    //     cout << "Selected(" << index << ", " << "Added): ";
    //     cout << A[index] + X << endl;
    // }

    return cache[index][K];
}

void solution() {
    IN(N, int);
    IN(X, int);

    VEC(int) A(N);

    FOR(i, 0, N) {
        cin >> A[i];
    }

    for(int k = 0; k <= N; ++k) {
        vector<int>copy(A.begin(), A.end());
        vector<vector<int>> cache(N, vector<int>(N + 1, -1));
        cout << max_subarray_sum(0, copy, N, k, X, cache) << " ";
    }
    cout << endl;
}