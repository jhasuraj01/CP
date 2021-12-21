#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, X, Y, max_Y = 1;

    vector <int> primer(10000001, 1);
    primer[0] = 0;
    primer[1] = 0;

    for (int n = 2, ptr = 0; n <= 10000001; n++)
    {
        if (primer[n])
        {
            primer[n] = primer[n-1] + 1;
        }
        else
        {
            primer[n] = primer[n-1];
        }

        for (int j = n*2; j <= 10000001; j += n)
        {
            primer[j] = 0;
        }
    }

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> X >> Y;
        cout << Y - X - primer[Y] + primer[X+1] << "\n";
    }
    return 0;
}