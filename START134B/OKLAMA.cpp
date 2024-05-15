
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

ll maximizeValue(multiset<ll>& B) {
  while (B.size() > 1) {
    auto it_max1 = prev(B.end());
    auto it_max2 = prev(it_max1);
    auto it_min = B.begin();

    ll max1 = *it_max1;
    ll max2 = *it_max2;
    ll min_val = *it_min;

    ll new_value = max1 + max2 - min_val;

    B.erase(it_max1);
    B.erase(it_max2);
    B.erase(it_min);

    B.insert(new_value);
  }

  return *B.begin();
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < Q; i++) {
    int K;
    cin >> K;
    // cerr << "K: " << K << endl;
    multiset<ll> B(A.begin(), A.begin() + K);
    // cerr << "B: ";
    // for (auto b : B) {
    //   cerr << b << " ";
    // }
    // cerr << endl;
    cout << maximizeValue(B) << " ";
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
