#include<bits/stdc++.h>
#include <string>

int ctoi(char num) {
    return (int)num - 48;
}

using namespace std;

int main() {
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        char s;
        cin >> N;
        int S[N];
        for (int i = 0; i < N; i++)
        {
            cin >> s;
            S[i] = ctoi(s);
        }

        int count = 0;

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (j - i == abs(S[j] - S[i]))
                {
                    count++;
                }
            }
        }

        cout << count << endl;

    }

    return 0;
}