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
    IN(R, int);
    IN(G, int);
    IN(B, int);

    vector<pair<int, int>> edge;
    string color = "B";
    --B;

    if(R < G) {
        while (R > 0)
        {
            color += "R";
            edge.push_back({1, color.size()});
            --R;
        }
        int index = 2;
        while(B > 0 && G > 0) {
            color += "GB";
            edge.push_back({index, color.size() - 1});
            edge.push_back({color.size() - 1, color.size()});
            --G;
            --B;
        }

        if(B > 0) {
            cout << -1 << endl;
            return;
        }

        while(G > 0) {
            color += "G";
            edge.push_back({1, color.size()});
            --G;
        }
    }
    else {
        while (G > 0)
        {
            color += "G";
            edge.push_back({1, color.size()});
            --G;
        }
        int index = 2;
        while(B > 0 && R > 0) {
            color += "RB";
            edge.push_back({index, color.size() - 1});
            edge.push_back({color.size() - 1, color.size()});
            --R;
            --B;
        }

        if(B > 0) {
            cout << -1 << endl;
            return;
        }

        while(R > 0) {
            color += "R";
            edge.push_back({1, color.size()});
            --R;
        }
    }

    cout << color << endl;

    for(auto e: edge) {
        cout << e.first << " " << e.second << "\n";
    }
}

/*

R: 2, G: 3, B: 4

BG

1 2
2 3
3 4

2 5
5 6

3 8
8 9

*/