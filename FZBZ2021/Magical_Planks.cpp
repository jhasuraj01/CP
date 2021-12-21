#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    for (auto e : v) os << e << " ";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, pair <T, T> &p)
{
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}


void solution() {
    int N;
    cin >> N;

    int W =0, B = 0;

    char c, last_c = '1';

    for (int i = 0; i < N; ++i)
    {
        cin >> c;
        if(c == 'W' && last_c != 'W') ++W;
        if(c == 'B' && last_c != 'B') ++B;
        last_c = c;
    }

    // cout << "W: " << W << ", B: " << B << endl;

    cout << min(W, B) << endl;
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


/*

WBW BWB WBW BWB WBW 15/3

WWWBBBWWW BBBWWW 5/3

WWWWWWWWWWWWWWW 2/3
*/