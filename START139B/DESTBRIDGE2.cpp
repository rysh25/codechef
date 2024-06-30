
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
  ll N, C;
  cin >> N >> C;

  // cerr << "N: " << N << " C: " << C << endl;

  ll a1 = 0;
  vector<ll> A(N - 1);
  rep(i, N) {
    if (i == 0) {
      cin >> a1;
    } else {
      cin >> A[i - 1];
    }
  }

  // cerr << "a1: " << a1 << endl;
  // cerr << "A: ";
  // for (auto a : A) {
  //   cerr << a << " ";
  // }
  // cerr << endl;

  ll b1cost = 0;

  for (int i = 0; i < N - 1; i++) {
    b1cost += a1 * A[i];
  }

  if (b1cost <= C) {
    // cerr << "b1cost: " << b1cost << endl;
    cout << 1 << endl;
    return;
  }

  sort(A.begin(), A.end());

  // cerr << "A: ";
  // for (auto a : A) {
  //   cerr << a << " ";
  // }
  // cerr << endl;

  set<int> destroyed;

  ll cost = 0;
  for (int i = 0; i < N - 1; i++) {
    // cerr << "i: " << i << endl;

    cost += a1 * A[i];

    for (int j = 0; j < N - 1; j++) {
      if (destroyed.count(j) > 0) {
        continue;
      }
      if (i == j) {
        continue;
      }

      // cerr << "j: " << j << endl;

      // cerr << "cost: " << cost << " A[i]: " << A[i] << " A[j]: " << A[j]
      //      << endl;

      cost += A[i] * A[j];
    }

    // cerr << "cost: " << cost << endl;
    if (cost > C) {
      break;
    }
    destroyed.insert(i);
  }

  // cerr << "destroyed: " << destroyed.size() << endl;

  cout << N - destroyed.size() << endl;
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
