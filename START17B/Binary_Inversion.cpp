#include<bits/stdc++.h>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto e : vector) {
        os << "{" << e.o << ", " << e.i << ", " << e.z << "}";
    }
    return os;
}

struct par {
    int o, i, z;
};

bool acc(par A, par B) {
    if (A.o != B.o)
    {
        return A.o < B.o;
    }

    if (A.i != B.i)
    {
        return A.i < B.i;
    }

    return (A.z < B.z);
}

void solution() {
    int N, M;
    char b;
    cin >> N >> M;

    string S;

    // 1's Inversions
    vector<par> D(N); 

    for (int i = 0; i < N; ++i)
    {
        cin >> S;
        int zeros = 0;

        for (int j = M-1; j >= 0; --j)
        {
            b = S[j];
            if(b == '1') {
                D[i].o += 1;
                D[i].i += zeros;
            }
            else
            {
                D[i].z += 1;
                zeros += 1;
            }
        }
    }


    sort(D.begin(), D.end(), acc);

    // cout << D << endl;

    long long int ans = 0;
    long long int totalZeros = 0;

    for (int i = 0; i < N; ++i)
    {
        ans += D[N-1-i].i + D[N-1-i].o * totalZeros;

        totalZeros += D[N-1-i].z;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution();
    }

    return 0;
}