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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void solution();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

string min_merge(string& A, string& B, int a, int b, int N, unordered_map<pair<int, int>, string, hash_pair>& cache) {

    if(a == N) {
        return B.substr(b);
    }
    else if(b == N) {
        return A.substr(a);
    }
    else if(cache.count({a, b})) return cache[{a, b}];

    string ma = A[a] + min_merge(A, B, a+1, b, N, cache);
    string mb = B[b] + min_merge(A, B, a, b+1, N, cache);

    cout << "ma: " << ma << "\nmb: " << mb << endl;

    return cache[{a, b}] = min(ma, mb);
}

void solution() {
    IN(N, int);
    IN(A, string);
    IN(B, string);

    unordered_map<pair<int, int>, string, hash_pair> cache;
    string res = min_merge(A, B, 0, 0, N, cache);

    long long int inversions = 0, ones = 0;
    N *= 2;

    for(int i = 0; i < N; ++i) {
        if(res[i] == '1') {
            ++ones;
        }
        else {
            inversions += ones;
        }
    }

    // cout << res << ": ";
    cout << inversions << endl;
}