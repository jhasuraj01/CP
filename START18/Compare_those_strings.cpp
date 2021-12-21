#include<bits/stdc++.h>
using namespace std;

void solution() {

    int N; cin >> N;
    string A, B;
    cin >> A >> B;

    int index = 0;
    int valid = 1;

    for (int i = 0; i < N; i++)
    {
        if (A[N-1-i] < B[N-1-i])
        {
            ++index;
            valid = 1;
        }
        else if(valid && index && A[N-1-i] == B[N-1-i]) {
            ++index;
        }
        else {
            valid = 0;
        }
    }

    cout << index << "\n";
    
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