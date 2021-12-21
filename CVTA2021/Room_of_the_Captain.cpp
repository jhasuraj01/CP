#include<bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    
    string n;

    unordered_map <string, int> fq;

    while(cin >> n) {
        fq[n] += 1;
    }
    
    for (auto e : fq)
    {
        if(e.second <= 1) {
            cout << e.first << "\n";
        }
    }
    return 0;
}