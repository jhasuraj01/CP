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
    IN(N, long long int);


    long long int min_cost = numeric_limits<long long int>::max();
    long long int cost1 = numeric_limits<long long int>::max();
    long long int cost2 = numeric_limits<long long int>::max();
    long long int min_int = numeric_limits<long long int>::max();
    long long int max_int = numeric_limits<long long int>::min();

    long long int l, r, c;

    for(long long int i = 0; i < N; ++i) {
        cin >> l >> r >> c;

        if (min_int > l && max_int < r)
        {
            min_int = l;
            max_int = r;
            min_cost = c;
 
            cost1 = min(c, cost1);
            cost2 = min(c, cost2);
        }
        else if(min_int == l && max_int < r) {
            max_int = r;
            min_cost = c;
            cost1 = min(c, cost1);
            cost2 = c;
        }
        else if(max_int == r && min_int > l) {
            min_int = l;
            min_cost = c;
            cost1 = c;
            cost2 = min(c, cost2);
        }
        else if (min_int > l || max_int < r) {
            min_int = min(min_int, l);
            max_int = max(max_int, r);

            if (min_int == l) {
                cost1 = c;
            }
            if (max_int == r) {
                cost2 = c;
            }
            min_cost = cost1 + cost2;
        }
        else if(min_int == l && max_int == r) {
            cost1 = min(c, cost1);
            cost2 = min(c, cost2);

            min_cost = min(min_cost, c);
        }
        else if(min_int == l) {
            cost1 = min(c, cost1);
            min_cost = min(min_cost, cost1 + cost2);
        }
        else if(max_int == r) {
            cost2 = min(c, cost2);
            min_cost = min(min_cost, cost1 + cost2);
        }
        cout << min_cost << endl;
    }

    // SORT(A);
}