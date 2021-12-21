// X,Y,A,B,K
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,X,Y,A,B,K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> X >> Y >> A >> B >> K;

        int p = X + K*A;
        int d = Y + K*B;

        if (d > p)
        {
            cout << "PETROL\n";
        }
        else if(p > d)
        {
            cout << "DIESEL\n";
        }
        else
        {
            cout << "SAME PRICE\n";
        }
    }
    
    return 0;
}