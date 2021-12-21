#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N, L, X;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> L >> X;
        if (L <= N/2)
        {
            cout << L*X << "\n";
        }
        else
        {
            cout << (N-L)*X << "\n";
        }
    }
    
    return 0;
}