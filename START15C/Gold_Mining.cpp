#include <iostream>
using namespace std;

int main() {
    int T, N, X, Y;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> X >> Y;
        if ((N+1)*Y >= X)
        {       
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
}