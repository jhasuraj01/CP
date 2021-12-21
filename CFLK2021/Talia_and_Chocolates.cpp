#include<bits/stdc++.h>
using namespace std;

double ncr(int n, int k) {

    if (k == 1)
    {
        return n;
    }
    else if (k == 0) {
        return 1;
    }
    else if (k == n) {
        return 1;
    }

    return ncr(n-1, k) + ncr(n-1, k-1);
}

void solution() {
    int N, K;
    cin >> N >> K;

    cout << ncr(K + N - 1, N - 1) << "\n";
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