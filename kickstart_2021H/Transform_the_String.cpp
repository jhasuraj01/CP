#include<bits/stdc++.h>
using namespace std;

void out(int x, int y) {
    cout << "Case #" << x << ": " << y << "\n";
}

int prev(int x, int d) {
    return (x-d < 0) ? (26 + x - d) : (x - d);
}

int next(int x, int d) {
    return (x+d)%26;
}

void solution(int x) {
    string S, F;
    cin >> S >> F;
    int s = S.size(), f = F.size();

    // bitset<26> Sb, Fb;
    unordered_map<int, int> Sb, Fb;

    for (int i = 0; i < f; ++i)
    {
        Fb[F[i] - 'a'] = 1;
    }

    for (int i = 0; i < s; ++i)
    {
        int letter_index = S[i] - 'a';

        if (Fb[letter_index] == 0)
        {
            Sb[letter_index] += 1;
        }
    }
    

    int operations = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (Sb[i])
        {
            int dist = 0;
            do
            {
                ++dist;

                if (Fb[prev(i, dist)] || Fb[next(i, dist)])
                {
                    operations += dist * Sb[i];
                    break;
                }

            } while (dist < 13);
            
        }
    }
    
    out(x, operations);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution(t+1);
    }

    return 0;
}