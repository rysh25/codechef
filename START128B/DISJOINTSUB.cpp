
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

    pair<int, int> mx = make_pair(-1, -1); // value, index
    vector<int> index(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (A[i] < mx.first)
        {
            index[i] = mx.second;
        }

        if (A[i] > mx.first)
        {
            mx.first = A[i];
            mx.second = i;
        }
    }

    // cout << "index:" << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << index[i] << " ";
    // }
    // cout << endl;

    int prev_add_val = -1;
    for (int i = 0; i < N; i++)
    {
        if (index[i] != -1)
        {
            if (prev_add_val > A[i])
            {
                cout << "No" << endl;
                return;
            }
            if (i > 0 && index[i - 1] != -1)
            {
                cout << "No" << endl;
                return;
            }

            prev_add_val = A[i];
        }
    }

    cout << "Yes" << endl;
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
