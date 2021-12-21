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


/*
7 2

0010010
*/

template <typename T>
T substring_count(T n) {
    return (n*(n + 1)) / 2;
}

// 01010100
// 001010
void solution() {
    long long int N, M;
    cin >> N >> M;

    long long int zero = N - M; // 5

    if (zero <= M + 1)
    {
        cout << zero << endl;
        return;
    }

    if (M == 0)
    {
        cout << (long long int) substring_count(zero) << endl;
        return;
    }
    

    long long int group = M + 1; // 4
    long long int largeSize = ceil((double) zero / group);
    long long int largeGroup = zero % group;
    long long int smallSize = largeGroup ? largeSize - 1 : largeSize;
    long long int smallGroup = group - largeGroup;

    // cout << "groups: " << group << endl;
    // cout << "largeSize: " << largeSize << endl;
    // cout << "smallSize: " << smallSize << endl;
    // cout << "largeGroup: " << largeGroup << endl;
    // cout << "smallGroup: " << smallGroup << endl;

    long long int solution = largeGroup * substring_count(largeSize) + smallGroup * substring_count(smallSize);
    cout << solution << endl;

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
