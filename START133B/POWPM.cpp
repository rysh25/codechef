
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

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> B = A;

    sort(B.begin(), B.end());

    ll ans = 0;

    // cerr << "B: ";
    // rep(i, N)
    // {
    //     cerr << B[i] << " ";
    // }
    // cerr << endl;

    rep(i, N)
    {
        if (B.size() == 0)
            break;

        int x = A[i];
        int l = -1, r = B.size();

        while (abs(r - l) > 1)
        {
            int mid = l + (r - l) / 2;

            if (B[mid] <= x)
            {
                // cerr << "ok: " << " mid: " << mid << " B[mid]: " << B[mid] << " " << i + 1 << " " << x << endl;
                l = mid;
            }
            else
            {
                // cerr << "ng: " << " mid: " << mid << " B[mid]: " << B[mid] << " " << i + 1 << " " << x << endl;
                r = mid;
            }
        }

        // cerr << "i: " << i << " x: " << x << " l: " << l << " r: " << r << endl;

        if (l > -1)
        {
            // cerr << "A_" << i + 1 << ": " << A[i] << " N-r: " << N - r << endl;

            // for (int j = r; j < N; j++)
            // {
            //     cerr << "B[" << j << "]: " << B[j] << " ";
            // }
            // cerr << endl;
            ans += l + 1;
        }

        int j = 1e9;
        for (int i = B.size() - 1; i >= 0; i--)
        {
            if (B[i] > 1e9)
            {
                j = min(i, j);
            }
            else
            {
                B[i] *= B[i];
            }
        }

        if (j < 1e9)
            B.erase(B.begin() + j, B.end());
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
