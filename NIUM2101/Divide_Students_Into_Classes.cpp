#include<bits/stdc++.h>
using namespace std;

void solution() {
    int N, h;
    cin >> N;

    map<int, int> C;

    for (int i = 0; i < N; ++i)
    {
        cin >> h;
        C[h] += 1;
    }

    int size = C.size();

    if (size > 12)
    {
        cout << "no\n";
        return;
    }
    
    if (size == 12)
    {
        cout << "yes\n";
        return;
    }
    
    int diff = 12 - size;

    for (auto i = C.begin(); i != C.end(); ++i)
    {
        diff -= i->second - 1;
    }

    if (diff > 0)
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
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