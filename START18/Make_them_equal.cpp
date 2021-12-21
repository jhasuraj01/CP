#include<bits/stdc++.h>
using namespace std;

void solution() {
    int N;
    cin >> N;
    set<int> A;

    int n;
    for(int i = 0; i < N; ++i) {
        cin >> n;
        A.insert(n);
    }

    auto itr = A.begin();

    long long int sum = 0;

    int prv = 0;

    for (auto itr : A)
    {
        // cout << itr << "\n";
        if (prv)
        {
            sum += itr - prv;
        }
        prv = itr;
    }
    

    // do {
    //     auto prv = itr;
    //     ++itr;

    //     cout << "Prv: " << prv->first << "Itr: " << itr->first << "\n";

    //     sum += (itr->first - prv->first);

    // } while(itr != A.end());

    cout << sum << "\n";
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solution();
    }

    return 0;
}