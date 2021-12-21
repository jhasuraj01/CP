#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    long long int N, V, min, max;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> V;
        max = N *(N - 1)/2;
        if (V > N)
        {
            min = N - 1;
        }
        else
        {
            min = V + (N - V)*(N - V + 1)/2 - 1;
        }
        cout << max << " " << min << "\n";
    }

    return 0;
}