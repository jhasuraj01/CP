#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x = 0;
    double y = 0;
};

template <typename T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

// -1: anti-clockwise
// 0: linear
// 1: clockwise
// sgn(slope of ba - cb)
int curve(Point a, Point b, Point c)
{
    return sgn((b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x));
}

bool pointsAscending(Point &a, Point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

long long int min_p2(unordered_map<int, Point> Pp, long long int n, long long int left_most)
{
    long long int result = 0, ptr = left_most, next_point;

    do
    {
        ++result;

        next_point = (ptr + 1) % n;
        for (long long int i = 0; i < n; ++i)
        {
            if (i != ptr && i != next_point && curve(Pp[ptr], Pp[i], Pp[next_point]) >= 0)
                next_point = i;
        }

        ptr = next_point;

    } while (ptr != left_most);

    return result;
}


long long int min_p1(unordered_map<int, Point> Pp, long long int n)
{
    long long int result = 0, ptr = 0, next_point;

    for (int i = 1; i < n; i++)
        if (pointsAscending(Pp[i], Pp[ptr]))
            ptr = i;

    long long int left_most = ptr;

    do
    {
        ++result;

        next_point = (ptr + 1) % n;
        for (long long int i = 0; i < n; ++i)
        {
            if (i != ptr && i != next_point && curve(Pp[ptr], Pp[i], Pp[next_point]) >= 0)
                next_point = i;
        }

        ptr = next_point;

    } while (ptr != left_most);

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, x, y;
    long long int N;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        long long int size = (N*(N-1))/2;
        vector<Point> P(N);
        unordered_map<int, Point> Pp;

        for (int i = 0; i < N; ++i)
        {
            cin >> x >> y;
            P[i].x = x;
            P[i].y = y;
        }

        long long int index = 0;

        double left_most = 5e8;
        for (int i = 0; i < N - 1; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                // Point point;
                // point.x = (P[i].x + P[j].x) / 2;
                // point.y = (P[i].y + P[j].y) / 2;
                // Pp.push_back(point);
                // Pp[index++] = point;
                Pp[index].x = (P[i].x + P[j].x) / 2;
                left_most = min(left_most, Pp[index].x);

                Pp[index++].y = (P[i].y + P[j].y) / 2;
            }
        }

        cout << min_p2(Pp, size, left_most) << "\n";
    }

    return 0;
}