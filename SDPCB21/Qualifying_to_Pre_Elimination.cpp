#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, N, K, S[100000];
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        }
        sort(S, S + N, greater<int>());
        int min_score = S[K-1];
        
        for (int i = K; S[i] >= min_score && i < N; i++)
        {
            K++;
        }
        
        cout << K << endl;
    } 
}