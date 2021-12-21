#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, N, D;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> D;
        int strength[N];
        for (int i = 0; i < N; i++)
        {
            cin >> strength[i];
        }
        sort(strength, strength + N);
        
        // cal max ppl with start and end index
        int l = 0, r = 0, ppl_count = 0, left = 0, right = 0, i = 0;
        while(i < N)
        {
            if (strength[r] - strength[r-1] > D)
            {
                if (r - l > ppl_count)
                {
                    left = l;
                    right = r;
                    l = r;
                    ppl_count = right - left;
                } else {
                    l = r;
                }
            } else {
                r++;
            }

            i++;
        }

        cout << "Max Ppl: " << ppl_count << endl;
    }
    return 0;
}

/**

15 8 10 9 6

sort

6 8 9 10 15
r
l
L
R

*/