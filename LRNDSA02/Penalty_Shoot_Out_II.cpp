#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector<type> name(size, value)
#define VEC3(name, type, size) vector<type> name(size)
#define VEC2(name, type) vector<type> name

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
    IN(N, int);

    int points_A = 0, points_B = 0;
    int games_played_A = 0, games_played_B = 0;

    char bin;
    int s = -1;

    int limit = 2*N;

    FOR(i, 0, limit) {
        cin >> bin;
        
        if(i%2) {
            points_A += bin - '0';
            ++games_played_A;
        }
        else {
            points_B += bin - '0';
            ++games_played_B;
        }

        if (s < 0)
        {
            int dif = abs(points_A - points_B);

            if (
                (points_A < points_B && dif > N - games_played_A) ||
                (points_B < points_A && dif > N - games_played_B)
            ){
                s = i+1;
            }
        }
    }

    cout << (s < 0 ? 2*N : s) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}