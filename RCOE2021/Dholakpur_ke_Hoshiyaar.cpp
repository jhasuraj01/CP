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

unordered_map<long long int, int> cache;

template <typename T>
int MinGoodNumber(T N) {

    if(cache.count(N)) return cache[N];

    int min_num = numeric_limits<int>::max() - 1;
    long long int base = 3040;
    
    if(N == 0) {
        return 0;
    }
    if(N < base) {
        return min_num;
    }

    for (int i = 0; i <= 14; ++i)
    {
        if(min_num > 1) {
            if(N/base < 10ll) {
                min_num = min(min_num, MinGoodNumber(N - base) + 1);
            }
        }
        else {
            break;
        }
        base *= 10;
    }

    cache[N] = min_num;
    
    return min_num;
}

void solution() {
    IN(N, long long int);
    
    int inf = numeric_limits<int>::max() - 1;
    int res = MinGoodNumber(N);

    if(res >= inf) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }

}