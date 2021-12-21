#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;

        // if (N == 1)
        // {
        //     int a;
        //     cin >> a;
        //     cout << -1 << "\n";
        //     continue;
        // }

        if (N == 2)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << max(a,b) << " " << min(a,b) << "\n";
            }
            continue;
        }

        vector<int> A(N);
        deque<int> seq;

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        int last[2] = {0, 0};
        last[1] = A[N - 1];

        bool solution_exists = true;

        for (int i = N - 1; i >= 0; i--)
        {
            if (last[1] != A[i])
            {
                seq.push_back(A[i]);
            }
            else if (last[0] != A[i])
            {
                seq.push_front(A[i]);
            }
            else
            {
                solution_exists = false;
                break;
            }

            last[0] = last[1];
            last[1] = A[i];
        }

        if (solution_exists)
        {
            bool print_forward = true;
            for (int i = 0; i < N; i++)
            {
                if (seq[i] != seq[N - i - 1])
                {
                    if (seq[i] < seq[N - i - 1])
                    {
                        print_forward = false;
                    }
                    break;
                }
            }

            if (print_forward)
            {
                for (int i = 0; i < N; i++)
                {
                    cout << seq[i] << " ";
                }
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    cout << seq[N-i-1] << " ";
                }
            }
        }
        else
        {
            cout << -1;
        }

        cout << endl;
    }

    return 0;
}