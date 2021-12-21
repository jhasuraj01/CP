#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        vector <int> A(N);
        vector <int> D(N, 2147483647);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        int and_res;
        D[0] = A[0] & A[1];
        for (int i = 1; i < N; i++)
        {
            D[i] = A[0] & A[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                D[i] = max(D[i] & A[j], D[i]);
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << D[i] << " ";
        }

        cout << "\n";

    }

    return 0;
}

/*
     11101  11100
 110011100
1010011111
  11111111
1110010000

[2, 2, 4, 1, 1, 5, 4, 4, 2, 3 ]



*/