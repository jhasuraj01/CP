#include<bits/stdc++.h>
using namespace std;

void printV(int A[], int N) {
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
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

        int array_size = pow(2, N);
        int zxcvb = pow(2, N);
        int A[array_size] = {0};

        for (int i = 0; i < array_size; i++)
        {
            cin >> A[i];
        }
        
        int solution_exists = 1;
        while(solution_exists && array_size > 1) {
            sort(A, A + array_size);

            for (int i = 0, j = 0; j < array_size; j++)
            {
                if (A[j] == -1)
                {
                    continue;
                }

                int k = j;
                int find_pair = 1;
                int offset = 0;
                int current_skip = 0;

                while (find_pair && k+1 < array_size) {
                    if(A[k+1] == -1) {
                        k++;
                        current_skip++;
                    }
                    else if(abs(A[j] - A[k+1]) <= 1) {
                        k++;
                        offset++;
                        current_skip = 0;
                    }
                    else {
                        find_pair = 0;
                        if (offset == 0)
                        {
                            solution_exists = 0;
                        }
                    }
                }

                if (solution_exists == 0)
                {
                    break;
                }

                // cout << "Array: ";
                // printV(A, zxcvb);
                // cout << "\n";


                if (A[k] == -1)
                {
                    A[i++] = A[j] + A[k - current_skip];
                    A[k - current_skip] = -1;
                }
                else
                {
                    A[i++] = A[j] + A[k];
                    A[k] = -1;
                }

            }

            array_size /= 2;
        }

        
        // cout << "Array: ";
        // printV(A, zxcvb);
        // cout << "\n";

        if (solution_exists)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}