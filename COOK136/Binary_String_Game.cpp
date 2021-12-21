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

string flip(string s, int start, int end) {
    for (int i = start; i <= end; ++i)
    {
        s[i] = (s[i] == '0' ? '1' : '0');
    }
}

int min_dist(string str, int start, char c)
{
    int count = 0;
    for (int i = start; i < str.length(); i++)
    {
        if ((i & 1 && str[i] == c) || (!(i & 1) && str[i] != c)) {
            flip()
        }
            count++;
        c = (c == '0' ? '1' : '0');
    }
    return count;
}

void solution() {
    IN(N, int);
    IN(str, string);

    int max_move = min(min_dist(str, '0'), min_dist(str, '1'));

    cout << max_move << "\n";

    if(max_move & 1) {
        cout << "JJ\n";
    }
    else {
        cout << "Uttu\n";
    }

}

/*

10101

10011


*/