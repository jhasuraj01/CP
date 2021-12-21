#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long int Pa = 0, Pb = 0;

    for (int i = 0; i < N/2; ++i)
    {
        Pa += A[i];
        Pb += A[N/2 + i];
    }

    cout << (Pb - Pa);
    
    return 0;
}