
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
// #include <cstdlib>
#include <algorithm>
#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

using ll = long long;
using ull = unsigned long long;

void solve() {
  int N;
  cin >> N;

  vector<int> A(N);

  rep(i, N) { cin >> A[i]; }

  sort(A.begin(), A.end());

  int prev = A[0];
  int len = 1;

  ll ans = 1001001001001001001;
  for (int i = 1; i < N; i++) {
    if (A[i] == prev) {
      len++;
    } else {
      ans = min(ans, (ll)(N - len) * (ll)prev);
      len = 1;
      prev = A[i];
    }
  }

  ans = min(ans, (ll)(N - len) * (ll)prev);

  cout << ans << endl;
}

int main() {
  // auto begin = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
  // auto end = std::chrono::high_resolution_clock::now();
  // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
  // begin); cerr << "Time measured: " << elapsed.count() * 1e-9 << "
  // seconds.\n";

  return 0;
}
