#include<bits/stdc++.h>
using namespace std;

void solution() {
    int N, A, x, y;
    cin >> N >> A;
    
    // vector <int> O, A;
    unordered_map <string, bool> P;

    bool ans = false;

    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;

        if (x == 1)
        {
            if (P.count(to_string(y) + ":4"))
            {
                ans = true;
            }
            P[to_string(y) + ":1"] = true;

        } else if (y == 1) {
            if (P.count(to_string(x) + ":4"))
            {
                ans = true;
            }
            P[to_string(x) + ":1"] = true;
        }

        if (x == A)
        {
            if (P.count(to_string(y) + ":1"))
            {
                ans = true;
            }
            P[to_string(y) + ":4"] = true;

        } else if (y == A) {
            if (P.count(to_string(x) + ":1"))
            {
                ans = true;
            }
            P[to_string(x) + ":4"] = true;
        }
    }

    if (ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    /* code */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int T;
    // cin >> T;
    // for (int t = 0; t < T; t++)
    // {
        solution();
    // }

    return 0;
}