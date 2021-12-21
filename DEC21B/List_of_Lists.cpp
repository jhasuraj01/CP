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


void solution() {
    IN(N, int);

    unordered_map<int, int> freq;

    int num;
    int max_freq = 0;
    FOR(i, 0, N) {
        cin >> num;
        ++freq[num];
        max_freq = max(max_freq, freq[num]);
    }

    if(N == 1) {
        cout << 0 << endl;
    }
    else if (max_freq < 2)
    {
        cout << -1 << endl;
    }
    else
    {
        if (freq.size() == 1)
        {
            cout << 0 << endl;
        }
        else {
            cout << (N - max_freq + 1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

/*

1 1 1 1 1 2 2 3 

1 2 2 3 1
1
1
1

1 2 2 2 2 1
1 
1

*/