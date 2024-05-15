
#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

using ll = long long;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    if (N < 4 || M < 4 || N + M < 11)
    {
        cout << -1 << endl;
        return;
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    ll ans = 0;

    rep(i, 4)
    {
        ans += A[i];
        ans += B[i];
    }

    vector<int> C;

    for (int i = 4; i < N; i++)
    {
        C.emplace_back(A[i]);
    }

    for (int i = 4; i < M; i++)
    {
        C.emplace_back(B[i]);
    }

    sort(C.rbegin(), C.rend());

    for (int i = 0; i < 3; i++)
    {
        ans += C[i];
    }

    cout << ans << endl;
}

int main()
{
    // auto begin = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

    return 0;
}
