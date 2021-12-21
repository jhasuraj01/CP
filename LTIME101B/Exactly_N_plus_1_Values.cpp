#include<bits/stdc++.h>
using namespace std;

void solution1(int N) {
    long long int num = 1;
    cout << num << " ";
    for (int i = 1; i <= N; i++)
    {
        cout << num << " ";
        num *= (long long int) 2;
    }
    cout << "\n";
}

void solution2(int N) {
    int sum = 0;

    if (N == 1)
    {
        cout << "1 1\n";
        return;
    }
    

    for (int i = 1; i <= N-1; i++)
    {
        cout << i << " ";
        sum += i;
    }
    
    cout << N - 1 << " ";
    sum += N-1;

    cout << pow(2, N) - sum << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        solution1(N);
    }
    return 0;
}

/*

n = 4
2^n = 16

16
8 8
4 4 8
2 2 4 8
1 1 2 4 8

*/