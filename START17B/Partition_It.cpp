#include<bits/stdc++.h>
using namespace std;

template <typename S> ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto e : vector) {
        os << e << " ";
    }
    return os;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solution() {
    vector <int> P;
    vector <char> D(100, '0');

    char curr = 'F';
    D[1] = 'M';

    for (int i = 2; i < 100; ++i)
    {
        if (D[i] != '0') continue;

        for (int j = 0; j < 100; j += i)
        {
            if (j == 0)
            {
                cout << i << " ";
                P.push_back(i);
            }
            D[i + j] = curr;
        }
        curr = curr == 'F' ? 'M' : 'F';
    }



    int N, K;
    cin >> N >> K;

    cout << P << endl;

    // cin >> gm >> gf;


    // for (int i = 2; i < N; ++i)
    // {
    //     cin >> n;

    //     int gm = gcd(n, gm);
    //     int gf = gcd(n, gf);

    //     if ( gm == 1 && gf == 1)
    //     {
    //         F.push_back(n);
    //     }
    //     else if (gm == 1)
    //     {
    //         F.push_back(n);
    //     }
    //     else
    //     {
    //         M.push_back(n);
    //     }
    // }
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