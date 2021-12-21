#include<bits/stdc++.h>
using namespace std;

int MEX(vector <int> &A) {
    sort(A.begin(), A.end());

    int limit = A.size() - 1;

    if (A[0] != 0)
    {
        return 0;
    }

    for (int i = 0; i < limit; ++i)
    {
        if (A[i] != A[i+1] - 1) {
            return A[i] + 1;
        }
    }

    return A[limit] + 1;
}

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

void solution() {
    int N, K;
    cin >> N >> K;
    vector <int> A(N);

    int bs = (N * (N + 1)) / 2;
    vector <int> B(bs);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int counter = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            vector <int> temp(B.begin() + i, B.begin() + j + 1);
            int b = MEX(temp);
            B[counter++] = b;

            // cout << temp << ": MEX = " << b << "\n";
        }

        // cout << "I Run!\n";
    }

    sort(B.begin(), B.end());

    cout << B[K-1] << "\n";
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

    // vector <int> B {1, 2, 3};

    // cout << MEX(B);

    return 0;
}