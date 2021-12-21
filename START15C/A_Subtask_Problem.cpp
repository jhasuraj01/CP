#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M >> K;
        int scores[N];

        for (int i = 0; i < N; i++)
        {
            cin >> scores[i];
        }

        int all_clear = 1;
        for (int i = 0; i < N; i++)
        {
            if (scores[i] == 0)
            {
                all_clear = 0;
                break;
            }
            
        }

        if (all_clear)
        {
            cout << 100 << endl;
            continue;
        }

        int first_M_clear = 1;
        for (int i = 0; i < M; i++)
        {
            if (scores[i] == 0)
            {
                first_M_clear = 0;
                break;
            }
            
        }

        if (first_M_clear)
        {
            cout << K << endl;
            continue;
        }

        cout << 0 << endl;
    }
    
    return 0;
}