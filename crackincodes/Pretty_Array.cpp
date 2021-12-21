#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector< type > name(size, value)
#define VEC3(name, type, size) vector< type > name(size)
#define VEC2(name, type) vector< type > name
#define VEC(type) vector< type > 

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
    IN(N, long long int);

    long long int A;
    long long int three = 0;
    long long int one = 0;
    long long int two = 0;

    FOR(i, 0, N) {
        cin >> A;

        switch (A%4)
        {
        case 3:
            ++three;
            break;
        case 2:
            ++two;
            break;
        case 1:
            ++one;
            break;
        }
    }

    long long int free3 = max(three - one, (long long int) 0);
    long long int free2 = two%2;
    long long int free1 = max(one - three, (long long int) 0);

    // cout << "Free 3: " << free3 << endl;
    // cout << "Free 1: " << free1 << endl;

    int operations = two / (long long int) 2;

    if(free3 > free1) {
        operations += one;
        if(free2 && free3%4 == 2) {
            cout << operations + 3*(free3/4) + 2;
        }
        else if(free3%4 == 0) {
            cout << operations + 3*(free3/4);
        }
        else {
            cout << -1;
        }
    }
    else if(free3 < free1) {
        operations += three;
        if(free2 && free1%4 == 2) {
            cout << operations + 3*(free1/4) + 2;
        }
        else if(free1%4 == 0) {
            cout << operations + 3*(free1/4);
        }
        else {
            cout << -1;
        }
    }
    else {
        operations += three;
        if (two%2 == 0)
        {
            cout << operations;
        }
        else {
            cout << -1;
        }
        
    }

    cout << endl;
}