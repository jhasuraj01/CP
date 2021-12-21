#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, A;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int odds = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> A;
            if (A % 2)
            {
                odds++;
            }
        }

        cout << odds/2 << endl;
        
    }
    
    return 0;
}