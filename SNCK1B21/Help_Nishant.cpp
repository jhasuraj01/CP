#include<bits/stdc++.h>
using namespace std;

int seq_len(int K) {
    int a = K;
    int b = K;
    int c = 2*b - a - 1;
    int count = 0;

    while (c > 0)
    {
        count++;
        a = b;
        b = c;
        c = 2*b - a - 1;
    }

    return 2*count + 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int T, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> K;

        int count = floor((1 + sqrt(1 + 8*(K - 1)))/2)*2;

        cout << count << "\n";
    }

    return 0;
}