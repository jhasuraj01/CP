#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("output.txt", "w", stdout);
    

    int T = 1000000000;
    for (int t = 1; t < T; t++)
    {
        // cin >> K;
        int K = t;
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

        cout << K << " => " << 2*count + 2 << "\n";
    }

    return 0;
}