#include<bits/stdc++.h>
using namespace std;

void solution() {
    int X;
    cin >> X;

    int k = (int) log2(X + 1);

    cout << (long long int) pow(2, k) << "\n";
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