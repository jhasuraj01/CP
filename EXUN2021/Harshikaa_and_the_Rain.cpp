#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type) type var; cin >> var
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define VEC(type) vector< type > 
#define SORT(name) sort(name.begin(), name.end())

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

// Example: https://www.codechef.com/viewsolution/54414764
long long int const mod = 1e9+7;
long long int inverse_modulo(long long int p, long long int q)
{
    long long int expo = mod - 2;
    while (expo) {
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}
// long long int const inverse = inverse_modulo(1, 4);

long long binpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solution();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

void dfs(int node, int parent, vector<vector<int>> &G, vector<int> &ND, map<int, int> &df) {

    for (int child: G[node]) {
        if(child != parent) {
            ND[child] = ND[node] + 1;
            dfs(child, node, G, ND, df);
        }
    }

    if(G[node].size() == 1 && node != 0) {
        ++df[ND[node]];
    }
}

void solution() {
    IN(N, int);
    IN(M, int);

    vector<vector<int>> G(N);

    long long int a, b;
    FOR(i, 1, N) {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    vector<int> ND(N, 0);

    map<int, int> dist_freq;

    dfs(0, -1, G, ND, dist_freq);

    // cout << ND << endl;

    long long int max_dist = (*(dist_freq.rbegin())).first;

    // cout << max_dist;

    // return;

    // number of drops after (i + 1)th second;
    vector<int> drop_count(max_dist + 1, 0);

    for (int d = 1; d <= max_dist; ++d)
    {
        if(dist_freq.count(d)) {
            drop_count[d] = drop_count[d-1] + dist_freq[d];
        }
        else {
            drop_count[d] = drop_count[d-1];
        }
    }

    // total drops after (i + 1) second;
    vector<int> total_drops(drop_count.begin(), drop_count.end());

    for (int d = 1; d <= max_dist; ++d)
    {
        total_drops[d] += total_drops[d-1];
    }

    long long int lastshake = 0, shake, ans = 0;

    FOR(i, 0, M) {
        cin >> shake;

        long long int max_time = shake - lastshake - 1;

        ans += total_drops[min(max_time, max_dist)];

        if(max_time > max_dist) {
            ans += drop_count.back() * (max_time - max_dist);
        }

        lastshake = shake;
    }

    cout << ans << endl;
}