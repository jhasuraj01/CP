#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    // cin >> T;

    // for (int t = 0; t < T; t++)
    // {
        cin >> N;
        char B[N][N];
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }

        // eliminate +

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < N - 1; j++)
            {
                if (
                    B[i-1][j] == 'K' &&
                    B[i+1][j] == 'K' &&
                    B[i][j-1] == 'K' &&
                    B[i][j+1] == 'K' &&
                    B[i][j] == 'K'
                )
                {
                    B[i-1][j] = 1;
                    B[i+1][j] = 1;
                    B[i][j-1] = 1;
                    B[i][j+1] = 1;
                    B[i][j] = 1;
                }
            }
        }

        // check if K is present after elimination
        int ok = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (B[i][j] == 'K')
                {
                    ok = 0;
                }

                if(ok == 0) {
                    break;
                }
            }

            if(ok == 0) {
                break;
            }
        }

        if (ok == 1)
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    // }
    return 0;
}