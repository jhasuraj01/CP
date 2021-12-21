#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, A1[100], A0[100], one = 0;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int ones_sum = 0;
        for (int i = 0, j = 0, k = 0; i < N; i++)
        {
            if (one)
            {
                cin >> A1[j];
                ones_sum += A1[j++];
                one = 0;
            }
            else
            {
                cin >> A0[k++];
                one = 1;
            }
        }

        sort(A1, A1 + N/2);
        sort(A0, A0 + N - N/2, greater<int>());

        one = 0;
        for (int i = 0, j = 0, k = 0; i < N; i++)
        {
            if (one)
            {
                cout << A1[j++] << " ";
                one = 0;
            }
            else
            {
                cout << A0[k++] << " ";
                one = 1;
            }
        }
        cout << "\n";

        int max_subsec = 0;
        for (int i = 0; i < N - N/2 && ones_sum > 0; i++)
        {
            max_subsec += A0[i] * ones_sum;
            ones_sum -= A1[i];
        }
        cout << max_subsec << "\n";
    }
    return 0;
}