#include <bits/stdc++.h>
using namespace std;

long long int xor_value(vector<long long int> &A)
{
    long long int result = 0;

    for (auto &a: A)
    {
        result ^= a;
    }

    return result;
}

void print(vector<long long int> &A) {
    for (auto &a: A)
    {
        cout << a << " ";
    }
}

bool odd_once(vector<long long int> &A, int pos)
{
    int count = 0;
    for (auto &a: A)
    {
        count += (a >> pos) & 1;
    }
    return count%2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        vector<long long int> A(N);
        long long int x = 0;
        long long int max_num = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            max_num = max(max_num, A[i]);
        }

        for (int i = 0; max_num >> i; i++)
        {
            if (odd_once(A, i))
            {
                for (auto &a: A)
                {
                    a += (long long int) 1 << i;
                }
                x += (long long int) 1 << i;
            }
        }

        if (xor_value(A) == 0)
        {
            cout << x << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}