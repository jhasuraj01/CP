#include<bits/stdc++.h>
using namespace std;

// 6/15 = 0.4
// 8/20 = 0.4
// 10/25 = 0.4
void solution() {
    long long int N;
    cin >> N;

    long long int six = (N - N%6)/6;
    N -= six*6;
    long long int eight = (N - N%8)/8;
    N -= eight*8;
    long long int ten = (N - N%10)/10;
    N -= ten*10;

    // cout << N << endl;

    cout << (ten * 25 + eight * 20 + six * 15 + (N ? 15 : 0)) << "\n";

    // cout << ((N - N%6)/6)*15 + (N%6 ? 15 : 0)<< "\n";
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