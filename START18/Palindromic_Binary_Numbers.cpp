#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto e : v)
    {
        os << e << ", ";
    }
    return os;
}


int bitReverse(int a)
{
    int k = 0;
    int num = 0;
    while (a >> k)
    {
        num = (num << 1) | ((a >> k) & 1);
        ++k;
    }
    return num;
}

vector<int> pb;

void precompute()
{
    for (int i = 1; i <= 1000; ++i)
    {
        if (i == bitReverse(i))
        {
            pb.push_back(i);
        }
    }
}

void solution()
{
    int N;
    cin >> N;

    int startIndex = upper_bound(pb.begin(), pb.end(), N) - pb.begin() - 1;

    vector< pair<int, int> > ans;

    int len = 0;

    for (int i = startIndex; i >= 0; --i)
    {
        ans.push_back({pb[i], N/pb[i]});
        len += N/pb[i];
        N = N % pb[i];
    }

    cout << len << "\n";

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].second; j++)
        {
            cout << ans[i].first << " ";
        }
    }
    
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution();
    }

    return 0;
}