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

bool isVowel(char c) {
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

void solution() {
    IN(N, int);

    VEC(char) A(N), B(N);

    FOR(i, 0, N) {
        cin >> A[i];
    }
    FOR(i, 0, N) {
        cin >> B[i];
    }

    // cout << A << endl;

    int min_change = numeric_limits<int>::max();

    for (int c = 0; c < 26; ++c)
    {
        char C = (char) ('a' + c);
        int change = 0;
        for (int i = 0; i < N; ++i)
        {
            if (A[i] == B[i] || (A[i] == '?' && B[i] == C) || (A[i] == C && B[i] == '?'))
            {
                continue;
            }
            if (isVowel(A[i]) && isVowel(B[i])) {
                change += 2;
            }
            else if(isVowel(A[i]) == false && isVowel(B[i]) == false && A[i] != '?' && B[i] != '?') {
                change += 2;
            }
            else if(A[i] != '?' && B[i] != '?' && (isVowel(A[i]) || isVowel(B[i]))) {
                change += 1;
            }
            else if(A[i] == '?') {
                if (isVowel(C) && isVowel(B[i])) {
                    change += 2;
                }
                else if(isVowel(C) == false && isVowel(B[i]) == false) {
                    change += 2;
                }
                else if(isVowel(C) || isVowel(B[i])) {
                    change += 1;
                }
            }
            else if(B[i] == '?') {
                if (isVowel(C) && isVowel(A[i])) {
                    change += 2;
                }
                else if(isVowel(C) == false && isVowel(A[i]) == false) {
                    change += 2;
                }
                else if(isVowel(C) || isVowel(A[i])) {
                    change += 1;
                }
            }
        }
        min_change = min(change, min_change);
    }
    
    cout << min_change << endl;
}