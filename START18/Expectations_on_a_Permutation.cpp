#include<bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto e : v)
    {
        os << e << " ";
    }
    return os;
}

/*

3 -> 2 = 2!
4 -> 6 = 3!
5 -> 24 = 4!
*/
void solution() {
    int N;
    cin >> N;

    vector <int> A(N);

    for (int i = 1; i <= N; ++i)
    {
        A[i-1] = i;
    }


    do {
        cout << A << endl;
    } while(next_permutation(A.begin(), A.end()));

    // for (int i = 1; i <= N; ++i)
    // {
    //     for (int j = 1; j <= N; ++j)
    //     {
    //         if (i == j)
    //         {
    //             /* code */
    //         }
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