#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int a, b, c, A = 0, B = 0, C = 0;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> a >> b >> c;
        A+=a;
        B+=b;
        C+=c;
    }

    if (A == 0 && B == 0 && C == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    

    return 0;
}