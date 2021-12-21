#include <bits/stdc++.h>
using namespace std;

int Opr(string &S, char a, char b, char r, int s)
{
    
    int allow_squized = 0;
    int ptr = 0;
    for (int i = 0; i < s; ++i)
    {
        if (allow_squized && S[i - 1] == a && S[i] == b)
        {
            --ptr;
            S[ptr] = r;
            allow_squized = 0;
        }
        else
        {
            allow_squized = 1;
            S[ptr] = S[i];
        }
        ++ptr;
    }
    return ptr;
}

void solution(int x)
{
    int N;
    string S;
    char M[10] = {'2', '3', '4', '5', '6', '7', '8', '9', '0', '1'};
    cin >> N >> S;

    int s;
    int ptr = N;

    do
    {
        s = ptr;
        ptr = Opr(S, '0', '1', '2', ptr);
        ptr = Opr(S, '1', '2', '3', ptr);
        ptr = Opr(S, '2', '3', '4', ptr);
        ptr = Opr(S, '3', '4', '5', ptr);
        ptr = Opr(S, '4', '5', '6', ptr);
        ptr = Opr(S, '5', '6', '7', ptr);
        ptr = Opr(S, '6', '7', '8', ptr);
        ptr = Opr(S, '7', '8', '9', ptr);
        ptr = Opr(S, '8', '9', '0', ptr);
        ptr = Opr(S, '9', '0', '1', ptr);

    } while (ptr != s);

    cout << "Case #" << x << ": ";
    for (int i = 0; i < ptr; i++)
    {
        cout << S[i];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution(t + 1);
    }

    return 0;
}