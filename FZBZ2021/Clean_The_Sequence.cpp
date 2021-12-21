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
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    vector<int> U(K+1, 0);
    vector<int> SU(K+1, 0);
    
    int total_u = 0;

    cin >> A[0];
    int last_2 = 0;
    int last_1 = A[0];

    for (int i = 1; i < N; ++i)
    {
        cin >> A[i];
        if (A[i-1] != A[i])
        {
            ++U[A[i-1]];
            ++U[A[i]];
            ++total_u;
            
            if (last_2 && last_2 != A[i])
            {
                ++SU[A[i-1]];
            }

            last_2 = last_1;
            last_1 = A[i];
        }
    }

    // cout << "Total: " << total_u << endl;

    for (int i = 1; i <= K; ++i)
    {
        cout << total_u - U[i] + SU[i] << " ";
    }
    cout << endl;
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