#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector<type> name(size, value)
#define VEC3(name, type, size) vector<type> name(size)
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


void solution() {
    IN(N, int);

    VEC(long long int) A(N), S(N);

    
    cin >> A[0];
    S[0] = A[0];

    FOR(i, 1, N) {
        cin >> A[i];
        S[i] = min(S[i-1], A[i]);
    }
    cout << accumulate(S.begin(),S.end(), (long long int) 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}