#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    long long int x, y, z, m;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> x >> y >> z;
        
        m = max(max(x, y), z);
        bool nowinner = 0;

        if (
            (x == m && y == m ) ||
            (y == m && z == m ) ||
            (x == m && z == m )
        )
        {
            nowinner = 1;
        }
        

        // cout << m << endl;

        cout << (m == x ? nowinner : m - x + 1) << " ";
        cout << (m == y ? nowinner : m - y + 1) << " ";
        cout << (m == z ? nowinner : m - z + 1) << " ";

        cout << "\n";
    }
    
    return 0;
}