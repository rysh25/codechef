
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

const ull B = 1000000007;

// Rolling hash (うまくいっていない)
void solve() {
  string S;
  cin >> S;

  int n = S.size();

  if (n % 2 == 1) {
    cout << 0 << endl;
    return;
  }

  int l = n / 2;

  ull PR = 0, Q = 0;
  ll ans = 0;

  ull t1 = 1;
  ull t = 1;
  for (int i = 0; i < l; i++) {
    if (i < l - 1) {
      t1 *= B;
    }
    t *= B;
    Q = Q * B + S[i];
    PR = PR * B + S[i + l];
  }

  // cerr << " Q: " << Q << " PR: " << PR << endl;
  if (Q == PR) {
    ans++;
  }

  rep(i, n - l + 1) {
    // cerr << "i: " << i << " i+l=" << i + l << " S[i]: " << S[i]
    //      << " S[i + l]: " << S[i + l] << " Q: " << Q << " PR: " << PR <<
    //      endl;
    Q = Q * B + S[i + l] - S[i] * t;

    // cerr << " S[i] * t1=" << S[i] * t1 << " S[i + l] * t1=" << S[i + l] * t1
    //      << endl;
    PR = PR + S[i] * t1 - S[i + l] * t1;

    if (Q == PR) {
      // cerr << "i: " << i << " Q: " << Q << " PR: " << PR << endl;
      ans++;
    }
  }

  cout << ans << endl;
}

// Z algorithm
void solve2() {
  string S;
  cin >> S;

  int n = S.size();

  if (n % 2 == 1) {
    cout << 0 << endl;
    return;
  }

  auto z_func = [n](const string &t) -> vector<int> {
    vector<int> ans(n, 0);
    ans[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
      if (i < r) {
        ans[i] = min(ans[i - l], r - i);
      }
      while (i + ans[i] < n && t[i + ans[i]] == t[ans[i]]) {
        ans[i]++;
      }
      if (i + ans[i] > r) {
        r = i + ans[i];
        l = i;
      }
    }
    return ans;
  };

  auto front = z_func(S);
  reverse(S.begin(), S.end());
  auto back = z_func(S);

  // cerr << "S: " << S << endl;
  // cerr << "front: ";
  // for (auto x : front) {
  //   cerr << x << ' ';
  // }
  // cerr << endl;

  // cerr << "back: ";
  // for (auto x : back) {
  //   cerr << x << ' ';
  // }
  // cerr << endl;

  int l = n / 2;

  int ans = 0;

  for (int i = 0; i < n - l + 1; i++) {
    // cerr << "i=" << i << " front[i]=" << front[i]
    //      << " back[n-l-i]=" << back[n - l - i] << endl;
    ll matched = min(front[i], i) + min(back[n - l - i], n - l - i);
    // cerr << "matched=" << matched << endl;
    if (matched >= l) {
      ans++;
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
