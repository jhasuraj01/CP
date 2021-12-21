#include<bits/stdc++.h>
using namespace std;

// 8 10 11 12 13 14 15

void solution() {
    int N;
    long long int n;
    cin >> N;
    
    int rem1 = 0;
    int rem2 = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> n;
        if (n % 3 == 2)
        {
            rem2 += 1;
        }
        else if(n % 3 == 1) {
            rem1 += 1;
        }
    }

    if (rem2 == rem1)
    {
        cout << rem2 << "\n";
        return;
    }

    int move = max(rem2, rem1) - min(rem2, rem1);

    // cout << "move: " << move << endl;
    if (move % 3 == 0)
    {
        cout << (min(rem2, rem1) + 2*(move)/3);
    }
    else {
        cout << -1;
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