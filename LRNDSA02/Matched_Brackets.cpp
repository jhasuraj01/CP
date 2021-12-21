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

    stack<int> st;
    int max_len = 0;
    int max_len_pos = -1;
    int seq_len = 0;
    int max_seq_len = 0;
    int max_seq_len_pos = -1;

    int input;

    FOR(i, 0, N) {
        cin >> input;

        if (input == 1)
        {
            st.push(1);
            ++seq_len;
        }
        else
        {
            st.pop();
            ++seq_len;
        }

        if((int)st.size() > max_len) {
            max_len = (int)st.size();
            max_len_pos = i + 1;
        }

        if((int) st.size() == 0) {
            if(max_seq_len < seq_len) {
                max_seq_len = seq_len;
                max_seq_len_pos = i + 2 - seq_len;
            }
            seq_len = 0;
        }
    }

    printf("%d %d %d %d\n", max_len, max_len_pos, max_seq_len, max_seq_len_pos);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // IN(T, int);
    // FOR(t, 0, T) 
        solution();

    return 0;
}