#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int d = 5, n, x, y;
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            cin >> n;
            if (n == 1)
            {
                y = 1 + i;
                x = 1 + j;
            }
        }
    }

    cout << (3 - y + 3 - x) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int T;
    // cin >> T;
    // for (int t = 0; t < T; t++)
    // {
    solution();
    // }

    return 0;
}