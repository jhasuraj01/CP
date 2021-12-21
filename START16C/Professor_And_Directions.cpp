#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    char C;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        char Cc = '1', Cp = '0';
        int yes = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> Cc;
            if (Cc == Cp)
            {
                yes = 1;
            }

            // cout << "Round: " << i << endl;
            // cout << "C_p: " << Cp << endl;
            // cout << "C_c: " << Cc << endl;

            Cp = Cc;
        }

        if (yes)
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