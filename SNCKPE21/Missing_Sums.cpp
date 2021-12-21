#include<bits/stdc++.h>
using namespace std;

void solution() {
    int N; cin >> N;
    int count = 1;
    while(N--) {
        cout << count << " ";
        count += 2;
    }
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