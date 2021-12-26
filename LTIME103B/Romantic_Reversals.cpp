#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
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

long long binpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solution();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

void reverse(VEC(char) S, int start, int end) {
    while (end > start)
    {

        --end;
        ++start;
    }
    
}

void solution() {
    IN(N, int);
    IN(K, int);
    IN(S, string);

    stack<char> st;

    for (int i = N - 1; i >= K; --i)
    {
        st.push(S[i]);
    }

    int start = 0;
    int end = K - 1;
    bool flag = true;
    while (end >= start)
    {
        if (flag)
        {
            st.push(S[start++]);
        }
        else
        {
            st.push(S[end--]);
        }
        flag ^= 1;
    }
    
    string O = "";
    while (!st.empty())
    {
        O += st.top();
        st.pop();
    }

    cout << O << endl;
}

/*

abferty 
baferty 
faberty 
abferty 

bbaaa

ab

abbabaa

*/