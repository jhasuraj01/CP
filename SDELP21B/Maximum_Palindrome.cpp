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

int smallest_odd_divisor(int N) {
    for (int i = 3; i <= min(N, 26); i += 2)
    {
        if (N % i == 0)
        {
            return i;
        }
    }
    return 1;
}

void solution() {
    IN(N, int);

    if(N == 2) {
        cout << "ab" << endl;
        return;
    }

    if(N%2) {
        int group = smallest_odd_divisor(N);
        if(group == 1 || group == N) {
            FOR(i, 0, N) {
                if(i%2) {
                    cout << 'a';
                }
                else {
                    cout << 'b';
                }
            }
        }
        else {
            int limit = N/group;
            FOR(g, 0, limit) {
                for(int j = 0; j < group; ++j) {
                    if(g%2) {
                        cout << (char) ('a' + group - 1 - j);
                    }
                    else {
                        cout << (char) ('a' + j);
                    }
                }
            }
        }
        
    }
    else {
        int half = N/2;
        FOR(i, 0, half) {
            if(i%2) {
                cout << "aa";
            }
            else {
                cout << "bb";
            }
        }
    }
    cout << endl;
}

/*
bbaabbaa
baabbaab *
aabbaabb
abbaabba *

cbaabcabc
babababababababababababababab
abccbaabc
bbaabbaa
*/