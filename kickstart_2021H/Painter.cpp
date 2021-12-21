#include<bits/stdc++.h>
using namespace std;

void out(int x, int y) {
    cout << "Case #" << x << ": " << y << "\n";
}

void solution(int x) {
    int N;
    cin >> N;
    vector <bitset<3> > P(N);

    char c;
    for (int i = 0; i < N; ++i)
    {
        cin >> c;
        if (c == 'R' || c == 'O' || c == 'P' || c == 'A')
        {
            P[i][0] = 1;
        }
        if (c == 'Y' || c == 'O' || c == 'G' || c == 'A')
        {
            P[i][1] = 1;
        }
        if (c == 'B' || c == 'P' || c == 'G' || c == 'A')
        {
            P[i][2] = 1;
        }
    }

    long long int stroke = P[0].count();
    for (int i = 1; i < N; ++i)
    {
        if ((P[i-1] ^ P[i]).count())
        {
            for (int b = 0; b < 3; ++b)
            {
                if (P[i-1][b] == 0 && P[i][b] == 1)
                {
                    ++stroke;
                }
            }
        }
    }

    out(x, stroke);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution(t+1);
    }

    return 0;
}