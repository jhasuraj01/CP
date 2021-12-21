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

    solution();

    return 0;
}

void solution() {
    IN(a, long long int);
    IN(b, long long int);
    IN(Q, long long int);

    VEC(long long int) A(a), B(b);

    FOR(i, 0, a) cin >> A[i];
    FOR(i, 0, b) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long int x;

    FOR(q, 0, Q) {
        cin >> x;

        long long int Ae = lower_bound(A.begin(), A.end(), x) - A.begin();
        long long int Be = lower_bound(B.begin(), B.end(), x) - B.begin();

        long long int Aw = max(Ae - (long long int)1, (long long int)0);
        long long int Bw = max(Be - (long long int)1, (long long int)0);

        Ae = min(Ae, (long long int) A.size() - 1);
        Be = min(Be, (long long int) B.size() - 1);

        // cout << "X: " << x << endl;
        // cout << "A => West: " << A[Aw] << " East: " << A[Ae] << endl;
        // cout << "B => West: " << B[Bw] << " East: " << B[Be] << endl << "Ans: ";

        long long int TE = max(abs(x - A[Ae]), abs(x - B[Be]));
        long long int TW = max(abs(x - A[Aw]), abs(x - B[Bw]));

        long long int NA = min(abs(x - A[Ae]), abs(x - A[Aw]));
        long long int NB = min(abs(x - B[Be]), abs(x - B[Bw]));
        long long int ME = 2*min(NA, NB) + max(NA, NB);

        if(x < A[0] && x < B[0]) {
            // cout << "EAST: ";
            cout << TE;
        }
        else if(x > A[a-1] && x > B[b-1]) {
            // cout << "WEST: ";
            cout << TW;
        }
        else if(x > A[0] && x > B[0] && x < A[a-1] && x < B[b-1]) {
            // cout << "MIX: ";
            cout << min({TE, TW, ME});
        }
        else if(x < A[0] || x < B[0]) {
            // cout << "E MIX: ";
            cout << min({TE, ME});
        }
        else if(x > A[a-1] || x > B[b-1]) {
            cout << min({TW, ME});
        }
        else {
            // cout << "MIX: ";
            long long int NA = min(abs(x - A[Ae]), abs(x - A[Aw]));
            long long int NB = min(abs(x - B[Be]), abs(x - B[Bw]));
            cout << 2*min(NA, NB) + max(NA, NB);
        }

        cout << endl;
    }
}

// 199
// 101