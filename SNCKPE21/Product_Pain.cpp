#include <bits/stdc++.h>
using namespace std;

template <typename T>
long long int weight(vector<T> &B, int l, int r)
{

    // cout << "Case: #" << l << "," << r << endl;

    long long int Bi = B[r];
    long long int Bj;
    long long int Bk = B[l];

    double expected = (double) (Bi + Bk) / 2.0;

    cout << "Expected: " << expected << endl;

    int j = lower_bound(B.begin() + l, B.begin() + r + 1, expected) - B.begin();

    // cout << "j: " << j << endl;

    if (j == r)
    {
        Bj = B[j - 1];
    }
    else if (j == l) {
        Bj = B[j + 1];
    }
    else if (B[j] == expected)
    {
        Bj = B[j];
    }
    else if (B[j] - expected > expected - B[j-1]) {
        Bj = (j - 1 != l) ? B[j - 1] : B[j];
    }
    else {
        Bj = B[j];
    }

    // cout << "Bi: " << Bi << endl;
    // cout << "Bj: " << Bj << endl;
    // cout << "Bk: " << Bk << endl;

    return (Bi - Bj) * (Bj - Bk);
}

void solution()
{
    int N;
    cin >> N;

    vector<long long int> A(N);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    long long int sum = 0;
    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 2; j < N; ++j)
        {
            long long int w = weight(A, i, j);
            // cout << "W: " << w << endl;
            // printf("W(%d, %d) = %ld\n", i, j, w);

            sum += w;
        }
    }

    cout << sum << "\n";

}

int main()
{
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