#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (r == 1 && c == 1)
                {
                    cout << 'Q';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }

        for (int r = 3; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                if (r == c)
                {
                    cout << 'Q';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
    
    return 0;
}