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
    int n , l, r, k;
    cin >> n >> l >> r >> k;

    vector<long long int> A(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // cout << A << "\n";

    int index = lower_bound(A.begin(), A.end(), l) - A.begin();

    int count = 0;
    for (int i = index; A[i] <= r && i < n; ++i)
    {
        if(k >= A[i]) {
            ++count;
            k -= A[i];
        }
    }

    cout << count << "\n";
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