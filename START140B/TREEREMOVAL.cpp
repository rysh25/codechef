
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
  int N;
  cin >> N;

  vector<int> A(N);
  int mn = INT_MAX;
  int mn_idx = -1;
  rep(i, N) {
    cin >> A[i];
    if (A[i] < mn) {
      mn = A[i];
      mn_idx = i;
    }
  }

  vector<vector<int>> G(N, vector<int>());

  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 0; i < N; i++) {
    sort(G[i].rbegin(), G[i].rend(), [&](int u, int v) { return A[u] < A[v]; });
  }

  // cerr << "G: " << endl;
  // for (int i = 0; i < N; i++) {
  //   cerr << i << ": ";
  //   for (auto v : G[i]) {
  //     cerr << v << " ";
  //   }
  //   cerr << endl;
  // }

  auto dfs = [&](auto self, int u, int p, vector<int> &remove) -> void {
    for (auto v : G[u]) {
      if (v == p) {
        continue;
      }

      self(self, v, u, remove);
    }

    remove.emplace_back(u + 1);
  };

  vector<int> remove;
  dfs(dfs, mn_idx, -1, remove);

  cout << remove.size() - 1 << endl;
  for (int i = 0; i < remove.size() - 1; i++) {
    cout << remove[i] << " ";
  }
  cout << endl;
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
