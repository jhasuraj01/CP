#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, K;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        int N_sq = N*N;
        vector <int> num (N_sq, 0);

        for (int i = 0; i < N_sq; i++)
        {
            cin >> num[i];
        }

        sort(num.begin(), num.end());

        int median_index = N/2;

        for (int i = 1; i <= N_sq; i++)
        {
            cout << num[i-1] << " ";
            if (i % N == 0)
            {
                cout << "\n";
            }

        }

        int goodness = num[N*median_index];

        cout << goodness << "\n";
    }
    return 0;
}