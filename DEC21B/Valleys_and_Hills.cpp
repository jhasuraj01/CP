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
    IN(H, int);
    IN(V, int);

    int length;
    if (H == V)
    {
        length = 2 * (H + 1);
    }
    else
    {
        length = max(H, V) + 1 + min(H, V) + 2*(max(H,V) - min(H,V)) - 1;
    }

    cout << length << endl;

    // cout << "01";

    bool dig = H < V;

    if (dig == 1)
    {
        cout << "10";
    }
    else
    {
        cout << "01";
    }
    

    while(H > 0 || V > 0) {
        if (dig == 1)
        {
            cout << '1';
            --V;

            if (H <= 0 && V > 0)
            {
                cout << '1';
            }           
        }
        else
        {
            cout << '0';
            --H;

            if (V <= 0 && H > 0)
            {
                cout << '0';
            }
        }

        dig ^= 1;
    }
    cout << endl;
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

10 1
01010010010010010010010010010
0101010010010010010010010010
3 3
1 1 1

*/