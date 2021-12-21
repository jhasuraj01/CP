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

int precedence(char symbol) {
    switch (symbol)
    {
    case '(':
        return 4;
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '-':
    case '+':
        return 1;
    default:
        return 0;
    }
}

void solution() {
    IN(N, int);
    IN(S, string);

    stack<char> st;

    FOR(i, 0, N) {

        int pre = precedence(S[i]);

        while (pre > 0 && !st.empty() && precedence(st.top()) < 4 && precedence(st.top()) > pre)
        {
            cout << st.top();
            st.pop();
        }

        while (S[i] == ')' && st.top() != '(')
        {
            cout << st.top();
            st.pop();
        }
        if (S[i] == ')')
        {
            st.pop();
            continue;
        }


        if (pre)
        {
            st.push(S[i]);
        }
        else
        {
            cout << S[i];
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T) solution();

    return 0;
}

/*

String: A+(B*C-(D/E^F)*G)*H
Stack:  +*

Output: ABC*DEF^/G*-H
*/