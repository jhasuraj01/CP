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

    // IN(T, int);
    // FOR(t, 0, T)
    solution();

    return 0;
}

void solution() {
    IN(N, int);
    unordered_map<string, bool> variables;
    
    IN(variable, string);
    char last_char = variable[variable.length() - 1];

    FOR(i, 0, N-1) {
        cin >> variable;
        if(variables.count(variable)) {
            cout << "No\n";
            return;
        }
        else {
            if (variable[0] == last_char)
            {
                variables[variable] = true;
            }
            else {
                cout << "No\n";
                return;
            }
        }

        last_char = variable[variable.length() - 1];
    }
    cout << "Yes\n";
}