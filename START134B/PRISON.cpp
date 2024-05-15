
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

  vector<string> P(N);

  ll INF = 1001001001001001001;
  vector<vector<ll>> time(N, vector<ll>(M, INF));

  rep(i, N) { cin >> P[i]; }

  deque<pair<int, int>> q;

  int dr[] = {0, -1, 0, 1};
  int dc[] = {1, 0, -1, 0};

  for (int c = 0; c < M; c++) {
    time[0][c] = P[0][c] - '0';
    q.emplace_back(0, c);

    time[N - 1][c] = P[N - 1][c] - '0';
    q.emplace_back(N - 1, c);
  }
  for (int r = 0; r < N; r++) {
    time[r][0] = P[r][0] - '0';
    q.emplace_back(r, 0);

    time[r][M - 1] = P[r][M - 1] - '0';
    q.emplace_back(r, M - 1);
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop_front();

    ll t = time[r][c];

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
        continue;
      }

      int nt = P[nr][nc] - '0';

      if (time[nr][nc] <= t + nt) {
        continue;
      }

      time[nr][nc] = t + nt;
      q.emplace_back(nr, nc);
    }
  }

  // cerr << "time:\n";
  // rep(r, N) {
  //   rep(c, M) { cerr << time[r][c] << ' '; }
  //   cerr << '\n';
  // }

  ll ans = 0;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (P[r][c] == '0') {
        ans = max(ans, time[r][c]);
      }
    }
  }

  cout << ans << '\n';
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
