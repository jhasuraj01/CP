#include <iostream>
using namespace std;

int main() {
    int T, N, D, h;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> D;
        int filter = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> h;
            if (h >= D)
            {
                filter++;
            }
        }
        cout << filter << endl;       
    }
    
    return 0;
}