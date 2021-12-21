#include<bits/stdc++.h>
using namespace std;

template <typename S> ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto e : vector) {
        os << e << " ";
    }
    return os;
}

void solution() {
    string S;
    int N;
    cin >> N;

    for (int i = 1; i < N; ++i)
    {
        cin >> S;
    }

    int z = 0;
    int s = 0;
    int o = 0;

    for (int i = 0; i < N; ++i)
    {
        if(S[N-1-i] == '1')
        {
            s += (++o) * z;
        }
        else
        {
            ++z;
        }
    }

    if (z % 2)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
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