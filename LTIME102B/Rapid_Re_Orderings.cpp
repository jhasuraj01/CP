#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
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
    long long int N;
    cin >> N;

    if (N == 1)
    {
        long long int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << a << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return;
    }
    

    long long int const limit = 2*N;
    vector<long long int> B(limit, 0), A(N, 0);

    for (long long int i = 0; i < limit; ++i)
    {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    long long int a = 0;
    long long int noSolution = 0;

    for (long long int i = 1; i < N; i+=2)
    {
        if (
            B[i-1] == B[i] &&
            (
                (B[i] != B[i+1] && (N%2 || i < N-1)) ||
                (N%2 == 0 && i == N-1 && B[i] == B[i+1])
            )
        ){
            A[a++] = B[i];
        }
        else {
            noSolution = 1;
            break;
        }
    }

    if(N%2 == 0 && B[N-2] != B[N-1] || B[N-1] != B[N]) {
        cout << "-1\n";
        return;
    }

    if (noSolution)
    {
        cout << "-1\n";
        return;
    }

    for (long long int i = N + 2 - N%2; i < limit; i+=2)
    {
        if (B[i-1] == B[i] && B[i] != B[i+1])
        {
            A[a++] = B[i];
        }
        else {
            noSolution = 1;
            break;
        }
    }

    A[a++] = B[limit - 1];

    if (noSolution)
    {
        cout << "-1\n";
        return;
    }

    cout << A << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int T;
    cin >> T;
    for (long long int t = 0; t < T; ++t)
    {
        solution();
    }

    return 0;
}

/*
1 1 2 2 3 3  3 4 4 5 5 6
1 2 3 4 5 6
*/