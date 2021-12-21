#include <iostream>
#include <string>
#include <stack>
using namespace std;

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

void infixToPostfix(string S) {
    int N = S.size();

    stack<char> st;

    for(int i = 0; i < N; ++i) {

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
    infixToPostfix("3+5");
    return 0;
}
