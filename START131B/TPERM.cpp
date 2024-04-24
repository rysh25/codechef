
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

    auto ternary = [](int n)
    {
        string s;
        while (n)
        {
            s = to_string(n % 3) + s;
            n /= 3;
        }
        return s;
    };

    rep(i, N)
    {
        if ((i + 1) % 3 == 0)
        {
            cout << 2 + (i / 3 * 3) << " ";
            // cerr << 2 + (i / 3 * 3) << ":" << ternary(i + 1 + 2 + (i / 3 * 3)) << " ";
        }
        else if ((i + 1) % 3 == 1)
        {
            cout << 1 + (i / 3 * 3) << " ";
            // cerr << 1 + (i / 3 * 3) << ":" << ternary(i + 1 + 1 + (i / 3 * 3)) << " ";
        }
        else
        {
            cout << 3 + (i / 3 * 3) << " ";
            // cerr << 3 + (i / 3 * 3) << ":" << ternary(i + 1 + 3 + (i / 3 * 3)) << " ";
        }
    }
    cout << endl;
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
