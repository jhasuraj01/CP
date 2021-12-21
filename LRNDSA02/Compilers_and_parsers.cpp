#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector<type> name(size, value)
#define VEC3(name, type, size) vector<type> name(size)
#define VEC2(name, type) vector<type> name

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
    IN(S, string);
    int len = S.length();

    int load = 0;
    int pre_len = 0;

    FOR(i, 0, len) {
        if(S[i] == '<') {
            ++load;
        }
        else {
            --load;
            if(load == 0) {
                pre_len = i + 1;
            }
        }

        if(load < 0) {
            cout << pre_len << endl;
            return;
        }
    }

    cout << pre_len << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}