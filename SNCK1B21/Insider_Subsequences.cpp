#include <bits/stdc++.h>
using namespace std;

typedef int lli;
typedef vector<lli> v;
typedef vector<vector<lli>> vv;
typedef map<int, vector<vector<lli>>> mvv;


void print(vector<vector<int> > result)
{
    for (int i = 0; i < result.size();
         i++) {
 
        cout << "{";
        for (int j = 0; j < result[i].size();
             j++) {
 
            cout << result[i][j];
            if (j < result[i].size() - 1) {
 
                cout << ", ";
            }
        }
        cout << "} ";
    }
}

void backtrack(vector<int>& nums, int start,
               vector<vector<int> >& resultset,
               vector<int> curr_set)
{
    resultset.push_back(curr_set);
 
    for (int i = start; i < nums.size(); i++) {
 
        // If the current element is repeating
        if (i > start
            && nums[i] == nums[i - 1]) {
            continue;
        }
 
        // Include current element
        // into the subsequence
        curr_set.push_back(nums[i]);
 
        // Proceed to the remaining array
        // to generate subsequences
        // including current array element
        backtrack(nums, i + 1, resultset,
                  curr_set);
 
        // Remove current element
        // from the subsequence
        curr_set.pop_back();
    }
}

vector<vector<int> > AllSubsets(
    vector<int> nums)
{
    // Stores the subsequences
    vector<vector<int> > resultset;
 
    // Stores the current
    // subsequence
    vector<int> curr_set;
 
    // Sort the vector
    sort(nums.begin(), nums.end());
 
    // Backtrack function to
    // generate subsequences
    backtrack(nums, 0, resultset,
              curr_set);
 
    // Return the result
    return resultset;
}

mvv generate_subsets(vector<lli> v)
{
    mvv subsets;

    int N = v.size();

    for (int b = 1; b < (1 << N); b++)
    {
        vector<lli> subset;
        for (int i = 0; i < N; i++)
        {
            if (b & (1 << i))
                subset.push_back(v[i]);
        }
        subsets[subset.size()].push_back(subset);
    }

    return subsets;
}

bool is_nth_insider(vv subsets, int n)
{
    for (int i = 0; i < subsets.size(); i++)
    {
        v subset = subsets[i];
        bool insider = true;

        for (int j = 1; j < subset.size(); j++)
        {
            if (
                !((subset[j] > n && n > subset[j - 1]) ||
                  (subset[j] < n && n < subset[j - 1])))
            {
                insider = false;
                break;
            }
        }

        if (insider)
        {
            return true;
            break;
        }
    }

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        vector<lli> A(N);
        set<lli> A_set;
        vector<lli> m(N + 1, -1);
        vector<lli> M(N + 1, -1);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            A_set.insert(A[i]);
        }

        mvv subset_map = generate_subsets(A);
        vector<vector<int> > subsets = AllSubsets(A);

        print(subsets);

        // for (int i = 1; i < N; i++)
        // {
        //     print(subset_map[i]);
        //     cout << endl;
        // }
        

        // smallest mk -insider
        for (int l = 2; l <= N; l++)
        {
            vv subsets = subset_map[l];
            int counter = 0;
            for (auto it = A_set.begin(); counter < l; counter++)
            {
                if (is_nth_insider(subsets, *it + 1))
                {
                    m[l] = *it + 1;
                    break;
                }
                it++;
            }
            cout << m[l] << " ";
        }

        cout << "\n";

        // largets mk -insider
        for (int l = 2; l <= N; l++)
        {
            vv subsets = subset_map[l];

            int counter = N;
            for (auto it = A_set.end(); counter > N - l; --counter)
            {
                it--;

                if (is_nth_insider(subsets, *it - 1))
                {
                    M[l] = *it - 1;
                    break;
                }
            }
            cout << M[l] << " ";
        }

        cout << "\n";
    }

    return 0;
}