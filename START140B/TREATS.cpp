
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

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);

  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];

  vector<int> A_mod(M, 0), B_mod(M, 0);

  rep(i, N) {
    A_mod[A[i] % M]++;
    B_mod[B[i] % M]++;
  }

  ll ans = 0;

  rep(i, M) { ans += (ll)A_mod[i] * B_mod[(M - i) % M]; }

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
