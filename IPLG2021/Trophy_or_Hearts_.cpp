#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string S1, S2;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int count = 0, i = 0;
        int AS1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int AS2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        cin >> S1 >> S2;

        while(S1[i] != '\0' && S2[i] != '\0') {
            char s1 = tolower(S1[i]);
            char s2 = tolower(S2[i]);
            int sub = 97;

            AS1[(int) s1 - sub] = 1;
            AS2[(int) s2 - sub] = 1;

            i++;
        }

        i = 0;
        while (i < 26)
        {
            if(AS1[i] == 1 && AS2[i] == 1)
            {
                count++;
            }
            i++;
        }
        cout << count << endl;
    }
    return 0;
}