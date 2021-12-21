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

bool solutionExists(string &S, int index, int last_num, int max_num, int first_num) {

    if (index + 1 == S.size())
    {
        if(S[index] == 'E') return last_num == first_num;
        else return last_num != first_num;
    }

    if (S[index] == 'E')
    {
        return solutionExists(S, index + 1, last_num, max_num, first_num);
    }
    else {
        bool ans = false;
        for (int i = 0; i <= max_num; ++i)
        {
            if(i == last_num) continue;
            ans = ans || solutionExists(S, index + 1, i, max_num, first_num);
        }
        ans = ans || solutionExists(S, index + 1, max_num + 1, max_num + 1, first_num);
        
        return ans;
    }
    
}

void solution() {
    IN(S, string);

    // VEC(int) A(N);
    int last_num = 0, max_num = 0, first_num = 0, index = 0;

    if(solutionExists(S, index, last_num, max_num, first_num)) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}


/*


 E  N  N  E  E  E  E  N  NEENEE
[1, 1, 2, 1, 1, 1, 1, 2, 1]
[1, 1, 2, 1, 1, 1, 1, 2, 3]

[1, 1, 2, 1, 1, 1, 1, 3, 1]
[1, 1, 2, 1, 1, 1, 1, 3, 2]
[1, 1, 2, 1, 1, 1, 1, 3, 4]

[1, 1, 2, 3, 3, 3, 3, 1, ]
[1, 1, 2, 3, 3, 3, 3, 1, ]

[1, 1, 2, 3, 3, 3, 3, 2, ]

[1, 1, 2, 3, 3, 3, 3, 4, ]

*/