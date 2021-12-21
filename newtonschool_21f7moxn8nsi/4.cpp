#include <bits/stdc++.h>

using namespace std;

long long int ways(int x, int y, long long int time, vector<int> &R, vector<int> &C, vector< vector<int> > &G) {
    
    int Rn = R.size();
    int Cn = C.size();

    if(x == Cn - 1 && y == Rn - 1) {
        return time;
    }

    if (G[x][y] == time % 2)
    {
        return (long long int) -1;
    }
    else
    {
        G[x][y] = time % 2;
    }

    bool left = x > 0 ? (C[x-1] % 2 != (time + 1) % 2) && (R[y] % 2 != (time + 1) % 2) : false;
    bool right = x < Cn - 1 ? (C[x+1] % 2 != (time + 1) % 2) && (R[y] % 2 != (time + 1) % 2): false;
    bool up = y > 0 ? (R[y-1] % 2 != (time + 1) % 2) && (C[x] % 2 != (time + 1) % 2): false;
    bool down = y < Rn - 1 ? (R[y+1] % 2 != (time + 1) % 2) && (C[x] % 2 != (time + 1) % 2) : false;

    long long int min_time = numeric_limits<long long int>::max();
    long long int time_required;

    if(right) {
        time_required = ways(x + 1, y, time + (long long int) 1, R, C, G);
        if (time_required > (long long int) 0)
        {
            min_time = min(min_time, time_required);
        }
    }

    if(down) {
        time_required = ways(x, y + 1, time + (long long int ) 1, R, C, G);
        if (time_required > (long long int) 0)
        {
            min_time = min(min_time, time_required);
        }
    }

    if (min_time == numeric_limits<int>::max())
    {
        if(up) {
            time_required = ways(x, y - 1, time + (long long int) 1, R, C, G);
            if (time_required > (long long int) 0)
            {
                min_time = min(min_time, time_required);
            }
        }
        if(left) {
            time_required = ways(x - 1, y, time + (long long int) 1, R, C, G);
            if (time_required > (long long int)0)
            {
                min_time = min(min_time, time_required);
            }
        }
    }

    if (min_time == numeric_limits<long long int>::max())
    {
        return (long long int) -1;
    }
    else
    {
        return min_time;
    }
}

int main() {
    int N, M, K;

    cin >> N >> M >> K;

    vector<int> R(N, -1), C(M, -1);
    vector< vector<int> > G(N, vector<int>(M, -1));

    int r, c;
    char dir;

    for(int i = 0; i < K; ++i) {
        cin >> r >> c >> dir;
        R[r-1] = dir == 'R' ? 0 : 1;
        C[c-1] = dir == 'C' ? 0 : 1;
    }

    cout << ways(0, 0, (long long int) 0, R, C, G);

    return 0;
}