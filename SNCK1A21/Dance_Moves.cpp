#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    float X, Y;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> X >> Y;

        if (Y - X > 0)
        {
            float res = (Y-X)/2.0;

            if (res == (int) res)
            {
                cout << (int) res << endl;
            }
            else
            {
                cout << (int) res + 2 << endl;
            }
        }
        else
        {
            cout << X - Y << endl;
        }
    }
    
    return 0;
}