#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int a, b, c, lucky = 0;
        cin >> a >> b >> c;

        if (a == 7)
        {
            lucky = 1;
        }

        if (b == 7)
        {
            lucky = 1;
        }

        if (c == 7)
        {
            lucky = 1;
        }

        if (lucky)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
        
    }

    return 0;
}