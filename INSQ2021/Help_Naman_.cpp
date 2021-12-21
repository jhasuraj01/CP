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

// int min_cost(vector<pair<int, pair<int, int>>> A, int P, int Q, int p, int q, int cost) {
//     if(p > P && q > Q) {
//         return 0;
//     }


// }

void solution() {
    IN(P, int);
    IN(Q, int);
    IN(N, int);

    vector<pair<int, pair<int, int>>> A(N);
    vector<pair<int, pair<int, int>>> R;


    int s, t, g;
    FOR(i, 0, N) {
        cin >> s >> t >> g;
        A[i] = {g, {s, t}};
    }

    // sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i)
    {
        int pc = 0, qc = 0, cc = 0;
        for (int j = i; j < N; ++j)
        {
            pc += A[j].second.first;
            qc += A[j].second.second;
            cc += A[j].first;
            R.push_back({cc, {pc, qc}});
        }
    }

    sort(R.begin(), R.end());

    for (auto r: R)
    {
        cout << "Cost = " << r.first << ": {" << r.second.first << ", " << r.second.second << "}" << endl;
        // if (r.second.first >= P && r.second.second >= Q)
        // {
        //     cout << r.first << endl;
        //     break;
        // }
    }
    // cout << min_cost(A, P, Q, 0, 0, 0);
}