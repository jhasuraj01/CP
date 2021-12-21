#include<bits/stdc++.h>
using namespace std;

int travel(int x, int y, int N, int G[][N]) {

    if (x == N && y == N)
    {
        return 1;
    }

    int reached = 0;

    if (x + 1 < N && G[x+1][y] != 1)
    {
        reached = travel(x+1, y, N, G);
        if (reached)
        {
            return 1;
        }
    }
    else if (y + 1 < N && G[x][y+1] != 1)
    {
        reached = travel(x, y+1, N, G);
    }

    return reached;
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int x, y, G[N][N] = {0};
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            G[x][y] = 1;
        }

        int reached = travel(0, 0, N, G);
        if (reached)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}