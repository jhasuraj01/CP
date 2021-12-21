#include<bits/stdc++.h>
using namespace std;

void solution() {
    int N;
    cin >> N;
    vector <int> B(N);
    int pass = 1;

    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];

        if (i && (B[i] > B[i-1] || B[i-1] % B[i]))
        {
            pass = 0;
        }
    }

    if(pass) {
        for (int i = 0; i < N; ++i)
        {
            cout << B[i] << " ";
        }
    }
    else
    {
        cout << "-1";
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