#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll T, N, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        // int maxScore = (N - K + N%2 )*2;
        int maxScore = (16*N - 10*K - 1)/9 + 1;
        cout << maxScore << "\n";
    }

    return 0;
}