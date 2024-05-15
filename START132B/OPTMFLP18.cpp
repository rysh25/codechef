
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
    int N;
    cin >> N;

    vector<int> A(N);

    rep(i, N) cin >> A[i];

    ll ans = (ll)N * (ll)(N + 1) / 2;

    // cerr << "ans: " << ans << endl;

    int max_streak_odd = 0;
    int max_streak_odd_index = 0;
    int c = 0;
    rep(i, N)
    {
        if (A[i] % 2 == 1)
        {
            c++;
            if (c > max_streak_odd)
            {
                max_streak_odd = c;
                max_streak_odd_index = i;
            }
        }
        else
        {
            c = 0;
        }
    }

    if (max_streak_odd == 0)
    {
        cout << ans << endl;
        return;
    }

    A[max_streak_odd_index]++;

    c = 0;
    rep(i, N + 1)
    {
        if (i < N && A[i] % 2 == 1)
        {
            c++;
        }
        else
        {
            // cerr << "i: " << i << "c*(c+1)/2: " << (ll)c * (ll)(c + 1) / 2 << endl;
            ans -= (ll)c * (ll)(c + 1) / 2;
            c = 0;
        }
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
