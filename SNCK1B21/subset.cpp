#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences
void print(vector<vector<int>> result)
{
    for (int i = 0; i < result.size();
         i++)
    {

        cout << "{";
        for (int j = 0; j < result[i].size();
             j++)
        {

            cout << result[i][j];
            if (j < result[i].size() - 1)
            {

                cout << ", ";
            }
        }
        cout << "} ";
    }
}

int main()
{
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {55, 107, 93, 121, 31, 190, 92, 45, 110, 132, 198, 130, 120, 141, 161, 96, 192, 106, 199, 152, 37, 18, 103, 124, 95, 99, 11, 179, 28, 118, 72, 57, 129, 143, 73, 67, 22, 172, 157, 142, 150, 153, 56, 66, 98, 117, 123, 35, 180, 30, 174, 34, 114, 77, 133, 43, 17, 115, 171, 61, 13, 84, 194, 122, 178, 29, 71, 70, 19, 64, 176, 50, 63, 44, 91, 109, 186, 197, 183, 139, 59, 12, 78, 162, 82, 86, 128, 49, 151, 85, 14, 48, 163, 159, 26, 191, 62, 177, 116, 169};
    // int n = v.size();
    int n = 20;
    map<int, vector<vector<int>>> subsets;

    // for (int b = 0; b < (1 << n); b++)
    // {
    //     vector<int> subset;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (b & (1 << i))
    //             subset.push_back(v[i]);
    //     }
    //     subsets[subset.size()].push_back(subset);
    // }

    for (int b = 0; b < (1 << n); b++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (b & (1 << i))
                subset.push_back(i);
        }
        
        for (auto a : subset)
        {
            cout << a << " ";
        }
        
        cout << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     print(subsets[i]);
    //     cout << endl;
    // }

    return 0;
}