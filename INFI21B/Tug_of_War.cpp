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

void solution() {
    IN(N, int);
    IN(M, int);

    VEC(long long int) A(N), B(M);

    long long int amax = 0;
    int amaxf = 0;
    int last_amax = 0;
    int first_amax = 0;
    long long int bmax = 0;
    int bmaxf = 0;

    FOR(i, 0, N) {
        cin >> A[i];
        if (A[i] == amax)
        {
            ++amaxf;
            last_amax = i;
            first_amax = i;
        }
        else if(A[i] > amax) {
            amax = A[i];
            amaxf = 1;
            last_amax = i;
        }
    }
    FOR(i, 0, M) {
        cin >> B[i];
        if (B[i] == bmax)
        {
            ++bmaxf;
        }
        else if(B[i] > bmax) {
            bmax = B[i];
            bmaxf = 1;
        }
    }

    if (amax > bmax || (amax == bmax && amaxf > bmaxf))
    {
        cout << "NO" << endl;
        return;
    }

    if(amax == bmax && amaxf == bmaxf && amaxf == last_amax + 1) {
        cout << "NO" << endl;
        return;
    }

    sort(B.begin(), B.end());

    if (bmax > amax || (bmax == amax && bmaxf > amaxf))
    {
        cout << "YES" << endl;
        cout << B << endl;
        return;
    }
    

    long long int temp = B.end()[-bmaxf - 1];
    B.end()[-bmaxf - 1] = bmax;
    B.back() = temp;

    // if (B.back() < A.back())
    // {
        /* code */
    // }
    

    // cout << B << endl;

    // while (/* condition */)
    // {
    //     /* code */
    // }
    

    // cout << "YES" << endl;

}