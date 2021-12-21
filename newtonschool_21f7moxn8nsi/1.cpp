#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int M, Y, R, G;
    cin >> M >> Y >> R >> G;

    Y = max(Y + R, Y * G);

    if(Y > M) {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
    return 0;
}