#include<bits/stdc++.h>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& v)
{
    for (auto e : v) {
        os << e << " ";
    }
    return os;
}

void solution() {
    int N, K;
    cin >> N >> K;

    vector <int> A(N);

    for(int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    vector <int> B(N);

    int index = 0;
    for (int i = 0; i < K - 1; ++i)
    {
        B[index++] = A[i];
    }

    for (int i = K - 1; i < N; i += K)
    {
        for (int j = i + K - 1; j >= i; --j)
        {
            B[index++] = A[i];
        }
    }


    // for (int i = N - 1; i >= K - 1; --i)
    // {
    //     B[index++] = A[i];
    // }
    
    cout << B << endl;

    int len = 1;
    int maxlen = 0;
    for (int i = 1; i < N; i++)
    {
        if (B[i - 1] > B[i])
        {
            maxlen = max(len, maxlen);
            if (maxlen > K)
            {
                break;
            } else {
                len = 1;
            }
        }
        else {
            ++len;
        }
    }
    maxlen = max(len, maxlen);

    if (maxlen <= K)
    {
        cout << B;
    }
    else
    {
        cout << -1;
    }

    cout << "\n";
    // cout << "Maxlen: " << maxlen << endl;
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