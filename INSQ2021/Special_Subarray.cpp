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

    solution();

    return 0;
}

void len(VEC(int) &A, VEC(bool) &Ans, int l, int r, int max_num) {
    for (int i = l; i <= r; ++i)
    {
        int ans = 0;
        for (int j = i; j <= r; ++j)
        {
            ans |= A[j];
            if(ans == max_num) {
                Ans[j - i + 1] = true;
            }
        }
    }
}

void solution() {
    IN(N, long long int);

    VEC(long long int ) A(N);

    long long int  OR = 0;

    FOR(i, 0, N) {
        cin >> A[i];
        OR |= A[i];
    }

    long long int count = 0;
    while(OR >> count & 1) ++count;

    long long int max_num = 1 << (count + 1);

    long long int l = 0;
    long long int len = 0;
    long long int r = 0;

    for (; r < N; ++r)
    {
        if (A[r] >= max_num)
        {
            len = max(len, r - l);
            l = r+1;
        }
    }

    if(l < r) {
        len = max(len, r - l);
    }

    cout << len << endl;

}