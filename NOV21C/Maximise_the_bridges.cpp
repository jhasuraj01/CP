#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, M;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        for (int i = 1; i < N; i++)
        {
            cout << i << " " << i + 1 << "\n";
        }

        for (int i = N - 1, j = 3, k = 1; i < M; i++)
        {
            cout << j << " " << k << "\n";
            if (j - k > 2)
            {
                k++;
            }
            else
            {
                j++;
                k = 1;
            }
        }
        // cout << "\n";
    }
    
    return 0;
}