#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int R, I = 0, E = 0;

        for (int i = 0; i < 5; i++)
        {
            cin >> R;
            if (R == 1)
            {
                I++;
            }
            else if (R == 2)
            {
                E++;
            }
        }

        if (I > E)
        {
            cout << "INDIA" << endl;
        }
        else if (E > I)
        {
            cout << "ENGLAND" << endl;
        }
        else
        {
            cout << "DRAW" << endl;
        }
    }

    return 0;
}