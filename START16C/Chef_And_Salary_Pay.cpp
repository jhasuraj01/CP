#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, X, Y;
    char S;
    cin >> T;
    for (int t = 0; t < T; t++)
    {

        cin >> X >> Y;

        int longest_streak = 0, total_streak = 0, streak_count = 0;
        for (int i = 0; i < 30; i++)
        {
            cin >> S;

            if (S == '1')
            {
                total_streak++;
                streak_count++;
            } else {
                if (streak_count > longest_streak)
                {
                    longest_streak = streak_count;
                }
                streak_count = 0;
            }
        }

        if (streak_count > longest_streak)
        {
            longest_streak = streak_count;
        }

        int pay = total_streak * X + (longest_streak) * Y;

        cout << pay << endl;

    }
    
    return 0;
}