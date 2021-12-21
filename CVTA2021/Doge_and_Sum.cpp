#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int sum(int n) {
    return ( n * (n + 1) ) / 2;
}

void solution() {
    int D, N;
    cin >> D >> N;

    for (int i = 0; i < D; ++i)
    {
        N = sum(N);
    }
    cout << N << endl;
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

    return 0;
}