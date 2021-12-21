#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, X, Y;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> X >> Y;
        if ((X + 2*Y) % 2)
        {
            cout << "NO\n";
        }
        else
        {
            int x = X%2;
            int y = Y%2;

            if (x == 0 && y == 0)
            {
                cout << "YES\n";
            }
            else if (x == 0 && y == 1)
            {
                if (X >= 2)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else if (x == 1 && y == 0)
            {
                cout << "NO\n";
            }
            else if(x == 1 && y == 1)
            {
                cout << "NO\n";
            }

        }
        
    }
    
    return 0;
}