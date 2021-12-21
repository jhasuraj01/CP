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

int deploy(int n, vector<vector<int>> &R, int N) {
    
    int ans = 1;

    for (int i = 0; i < N; ++i)
    {
        ans += min(ans, deploy(i));
    }
    
    
}


void solution() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> R(N , vector<int> (N, 1));

    int x, y;
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y;
        R[x-1][y-1] = 0;
        R[y-1][x-1] = 0;
    }
    
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += deploy(i);
    }

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