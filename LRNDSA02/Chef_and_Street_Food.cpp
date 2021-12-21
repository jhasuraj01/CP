#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define VEC4(name, type, size, value) vector<type> name(size, value)
#define VEC3(name, type, size) vector<type> name(size)
#define VEC2(name, type) vector<type> name
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

    VEC(int) S(N), V(N), P(N), B(N, 0);

    FOR(i, 0, N) {
        cin >> S[i] >> P[i] >> V[i];
        
        B[i] = P[i] / (S[i] + 1);
    }

    int profit = 0;

    FOR(j, 0, N) {
        profit = max(profit, V[j] * B[j]);
    }

    cout << profit << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}