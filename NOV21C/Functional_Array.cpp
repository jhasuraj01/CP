#include<bits/stdc++.h>
using namespace std;
bool isSubSequence(vector <int> &A, vector <int> &B, int offset);


template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

void solution() {
    int N, M;
    cin >> N >> M;
    vector <int> B(N), Z(M);

    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < M; ++i) cin >> Z[i];

    if (N > M+1)
    {
        cout << "NO\n";
        return;
    }    

    int Bmax = *max_element(B.begin(), B.end());

    // possibilities
    // size of A: [N, M+1]

    for (int size = N-1; size <= M; ++size)
    {
        vector<bool> subset(M, 0);
        for (int i = 0; i < size; i++)
            subset[M-1-i] = 1;

        do
        {
            vector<int> A(size+1, 0);
            int a = 1;
            for (int i = 0; i < M; i++)
            {
                if (subset[i])
                {
                    A[a] = Z[i] + A[a - 1];
                    ++a;
                }
            }

            // cout << "Subset A: " << A << endl;
            int offset = 0;

            int Amax = *max_element(A.begin(), A.end());

            for (int offset = 0; Amax + offset <= Bmax; ++offset)
            {
                if (isSubSequence(B, A, offset))
                {
                    // cout << "A: ";
                    // for (auto x: A)
                    // {
                    //     cout << x+offset << " ";
                    // }
                    // cout << "\n";

                    cout << "YES\n";
                    return;
                }
            }
        } while (next_permutation(subset.begin(), subset.end()));        
    }

    cout << "NO\n";
}

bool isSubSequence(vector <int> &B, vector <int> &A, int offset)
{
    // cout << "isSubSequence: \n";
    // cout << "B: " << B << endl;
    // cout << "A: " << A << endl;

	int p = 0;
    int a = A.size(), b = B.size();

	for (int i = 0; i < a && p < b; ++i)
		if (A[i] + offset == B[p])
			++p;

	return (p == a);
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