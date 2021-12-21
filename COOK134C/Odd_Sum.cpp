#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;

        if (N == 1)
        {
            cout << 1;
        }
        else if(N == 2)
        {
            cout << 1;
        }
        else
        {
            cout << 1 + (N-2)*(N-1);
        }
        cout << "\n";
    }
    
    return 0;
}