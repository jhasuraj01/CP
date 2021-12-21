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
    int N;
    cin >> N;

    vector< pair<long long int, int> > A(N);
    deque<int> order;

    long long int temp;
    for(int i = 0; i<N; ++i) {
        cin >> temp;
        A[i] = {temp, i+1};
    }

    sort(A.begin(), A.end());

    order.push_back(0);

    for (int i = 0; i < N; ++i)
    {
        if (i % 2)
        {
            order.push_back(A[i].second);
        }
        else
        {
            order.push_front(A[i].second);
        }
    }

    vector <int> Ans(N+1);
    for(int i = 0; i <= N; ++i) {
        Ans[order[i]] = i;
    }

    cout << Ans << "\n";
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