#include<bits/stdc++.h>
using namespace std;

int power(int n) {
    int p = 0;
    while (n % 10) {
        p += n % 10;
        n /= 10;
    }

    return p;
}

void solution() {
    double PC, PR;
    cin >> PC >> PR;
    
    int digC = PC > 9 ? ceil((PC / 9.0)) : 1;
    int digR = PR > 9 ? ceil((PR / 9.0)) : 1;

    if (digC < digR)
    {
        cout << 0 << " " << digC << endl;
    }
    else {
        cout << 1 << " " << digR << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution();
    }

    return 0;
}