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

int CtOrderedPairs(int N)
{
    // Stores count of
    // ordered pairs
    int res = 1;
 
    // Calculate power of all
    // prime factors of N
    for (int i = 2; i * i <= N; i++) {
 
        // Store the power of
        // prime factors
        int countPower = 0;
        while (N % i == 0) {
            countPower++;
            N /= i;
        }
 
        res = res * (2 * countPower
                     + 1);
    }
 
    if (N > 1) {
        res = res * (2 * 1 + 1);
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

long long gcd(long long a, long long b){
    if(b == 0ll) return a;
    else return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

void solution() {
    IN(N, int);
    IN(M, int);

    if(M == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> factors;

    for (long long i = 2, limit = sqrt(M); i <= limit; ++i)
    {
        if(M % i == 0) {
            factors.push_back(i);
            if(M/i != i) {
                factors.push_back(M/i);
            }
        }
    }

    if(factors.size() == 0) {
        cout << 1 << endl;
        return;
    }
    sort(factors.rbegin(), factors.rend());

    vector<long long> col_sizes;
    col_sizes.push_back(factors[0]);

    for (int i = 1, limit = factors.size(); i < limit; ++i)
    {
        bool valid = true;
        for (int j = 0; j < col_sizes.size(); ++j)
        {
            if (lcm(col_sizes[j], factors[i]) != M)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            col_sizes.push_back(factors[i]);
        }
    }

    long long count = col_sizes.size();

    while(count && N % count) {
        --count;
    }

    cout << count << endl;

}