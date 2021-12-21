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
        int block = 0;
        char last_char = '2';
        char current_char;
        for (int i = 0; i < N; i++)
        {
            cin >> current_char;
            if (last_char != current_char)
            {
                block++;
                last_char = current_char;
            }
        }

        if (block % 2)
        {
            cout << "SAHID\n";
        }
        else
        {
            cout << "RAMADHIR\n";
        }
    }
    
    return 0;
}