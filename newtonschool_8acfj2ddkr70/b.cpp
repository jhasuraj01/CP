/**
 *    author:  tourist
 *    created: 28.12.2021 18:32:15       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return b[i] < b[j];
  });

  cout << "Order: ";
  for(auto a: order) {
    cout << a << " ";
  }
  cout << endl;

  const int N = 12345;
  vector<int> used(N);
  int ans = 0;
  for (int i : order) {
    int cnt = 0;
    for (int j = a[i]; j <= b[i]; j++) {
      cnt += used[j];
    }
    for (int j = b[i]; j >= a[i]; j--) {
      if (!used[j] && cnt < c[i]) {
        used[j] = 1;
        ans += 1;
        cnt += 1;
      }
    }
    assert(cnt >= c[i]);
  }
  cout << ans << '\n';
  return 0;
}