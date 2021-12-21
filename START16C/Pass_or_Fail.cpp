#include<bits/stdc++.h>
using namespace std;

int main() {
    int T,N,X,P;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> X >> P;
        int score = X*4 - N;
        if (score >= P)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    }
    return 0;
}