#include<bits/stdc++.h>
using namespace std;

void solution() {
    int A, B, P,Q;
    cin >> A >> B >> P >> Q;

    int abodd = abs(A-B) % 2;
    int pqodd = abs(P-Q) % 2;

    if(A == P && B == Q)
        cout << "0";
    else if(abodd == pqodd)
        cout << "2";
    else
        cout << "1";

    cout << "\n";
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