#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A, A+N);

        int ptr = N/2;
        int t_score = A[ptr];

        while(ptr > 0 && t_score == A[ptr - 1]) { ptr--; };

        cout << N - ptr << "\n";

    }

    return 0;
}