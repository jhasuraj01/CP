#include <bits/stdc++.h>

using namespace std;

int main()
{
    int R, C, a = 0, b = 0, c, d, luck = -1;
    cin >> R >> C;
    int M[R][C];

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> M[r][c];
        }
    }

    cin >> c >> d;

    for (int R = 0; R < c; R++)
    {
        for (int C = 0; C < d; C++)
        {
            // calc sum
            int sum = 0;
            for (int i = R; i < c; i++)
            {
                for (int j = C; j < d; j++)
                {
                    sum += M[i][j];
                }
            }

            if (sum > luck)
            {
                luck = sum;
                a = R;
                b = C;
            }
        }
    }

    if (luck >= 0)
    {
        cout << luck << endl;
        cout << a+1 << " " << b+1 << endl;
    }
    else {
        cout << 0 << endl;
        cout << "-1 -1" << endl;
    }

    return 0;
}