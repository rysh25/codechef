
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
    int N, K;
    cin >> N >> K;

    vector<int> k(K, 0);

    // vector<string> A(N);

    rep(i, N)
    {
        string s;
        cin >> s;

        int count_1 = 0;
        int x = 0;
        rep(j, K)
        {
            if (s[j] == '1')
            {
                count_1++;
                x = j;
            }
        }

        if (count_1 == 1)
        {
            k[x]++;
        }
    }

    // cerr << "k: ";
    // rep(i, K)
    // {
    //     cerr << k[i] << " ";
    // }
    // cerr << endl;

    rep(i, K)
    {
        if (k[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
