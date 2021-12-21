#include <bits/stdc++.h>
using namespace std;
int min_val(string &S, map<int, int> &bracket, unordered_map<string, int> &minmax, int l, int r);
int max_val(string &S, map<int, int> &bracket, unordered_map<string, int> &minmax, int l, int r);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, Q, l, r;
    string S;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> S;
        map<int, int> bracket;
        unordered_map<string, int> minmax;
        stack<int> bracket_stack;

        for (int i = 0; S[i] != '\0'; i++)
        {
            if (S[i] == '(')
            {
                bracket[i] = -1;
                bracket_stack.push(i);
            }
            else if (S[i] == ')')
            {
                bracket[bracket_stack.top()] = i;
                bracket_stack.pop();
            }
        }

        cin >> Q;
        for (int q = 0; q < Q; q++)
        {
            cin >> l >> r;
            cout << max_val(S, bracket, minmax, l - 1, r - 1) << " ";
        }
        cout << "\n";
    }

    return 0;
}


int min_val(string &S, map<int, int> &bracket, unordered_map<string, int> &minmax, int l, int r)
{
    if (S[l] == '?')
    {
        return 0;
    }

    string index = "min:" + to_string(l) + ":" + to_string(r);
    if (minmax.count(index))
    {
        return minmax[index];
    }

    int sign_index;
    int value = 0;

    if (S[l + 1] == '(')
    {
        int close_at = bracket[l + 1];
        value += min_val(S, bracket, minmax, l + 1, close_at);
        sign_index = close_at + 1;
    }
    else
    {
        sign_index = l + 2;
    }

    

    l = sign_index;
    if (S[l + 1] == '(')
    {
        int close_at = bracket[l + 1];
        if (S[sign_index] == '+')
        {
            value += min_val(S, bracket, minmax, l + 1, close_at);
        }
        else
        {
            value -= max_val(S, bracket, minmax, l + 1, close_at);
        }
    }
    else
    {
        if (S[sign_index] == '-')
        {
            value -= 1;
        }
    }
    minmax[index] = value;
    return value;
}

int max_val(string &S, map<int, int> &bracket, unordered_map<string, int> &minmax, int l, int r)
{
    if (S[l] == '?')
    {
        return 1;
    }

    string index = "max:" + to_string(l) + ":" + to_string(r);
    if (minmax.count(index))
    {
        return minmax[index];
    }

    int sign_index;
    int value = 0;

    if (S[l + 1] == '(')
    {
        int close_at = bracket[l + 1];
        value += max_val(S, bracket, minmax, l + 1, close_at);
        sign_index = close_at + 1;
    }
    else
    {
        value += 1;
        sign_index = l + 2;
    }


    l = sign_index;
    if (S[l + 1] == '(')
    {
        int close_at = bracket[l + 1];
        if (S[sign_index] == '+')
        {
            value += max_val(S, bracket, minmax, l + 1, close_at);
        }
        else
        {
            value -= min_val(S, bracket, minmax, l + 1, close_at);
        }
    }
    else
    {
        if (S[sign_index] == '+')
        {
            value += 1;
        }
    }

    minmax[index] = value;
    return value;
}
