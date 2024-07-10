
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
  int N, K, H;
  cin >> N >> K >> H;

  ll ans = 0;

  // if (N >= H) {
  //   ans += (ll)(H - N + 1) * N;
  // }

  // cerr << "N: " << N << ", K: " << K << ", H: " << H << endl;

  for (int i = 1; i <= N; i++) {
    // cerr << "i: " << i << endl;
    if (i >= H) {
      // cerr << "i >= H" << endl;
      ans += (ll)N;
    } else if (i > 1) {
      // cerr << "(H - i)=" << (H - i) << ", (K - 1)=" << (K - 1) << endl;
      int mn = ((H - i) + (K - 2)) / (K - 1);
      // cerr << "mn: " << mn << endl;

      if (mn >= 1 && i - mn > 0) {
        // cerr << "i-mn: " << (i - mn) << endl;
        ans += (ll)i - mn;
      }
    }
  }

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
