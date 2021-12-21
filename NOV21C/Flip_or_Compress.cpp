#include<bits/stdc++.h>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string S;
        int operation = 0;
        cin >> S;
        char lc = '-';
        vector<int> sv;

        for (auto &c : S)
        {
            if (lc == c)
            {
                sv.back() += 1;
            }
            else
            {
                lc = c;
                sv.push_back(1);
            }
        }

        if (sv.size() == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<int> temp1 { sv[0] };

        for (int i = 1, limit = sv.size(); i < limit; i++)
        {
            if (sv[i-1] > 1 && sv[i] == 1 && 1 < sv[i+1] && i+1 < limit)
            {
                // flip
                ++operation;

                temp1.back() += 1 + sv[i+1];
                i++;
            }
            else
            {
                temp1.push_back(sv[i]);
            }
        }

        // cout << sv << endl;

        sv = vector<int> (temp1.begin(), temp1.end());

        // cout << sv << endl;

        bool start = sv.size()%2 == 0 && sv[0] == 1 && sv[1] > 1 ? 0 : 1;

        for (int i = start, limit = sv.size() - sv.size()%2; i < limit; i+=2)
        {
            if (sv[i] > 1)
            {
                // compress & flip
                operation += 2;
            }
            else
            {
                // flip
                operation += 1;
            }
        }

        cout << operation << "\n";
    }

    return 0;
}