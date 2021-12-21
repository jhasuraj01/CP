#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N, A, B, ci;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int score = 0;
        cin >> N >> A >> B;

        for (int i = 2; N > 1; )
        {
            if (N % i == 0)
            {
                N = N/i;

                if (i % 2)
                {
                    score += B;
                }
                else
                {
                    score += A;
                }

            } else {
                ++i;
            }
        }

        cout << score << endl;

    }
    
    return 0;
}