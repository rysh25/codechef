
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
    int A, B;
    cin >> A >> B;

    if (A == B)
    {
        cout << 0 << endl;
        return;
    }

    int diff = abs(A - B);
    int sum = 0, i = 1;

    // cout << "diff=" << diff << endl; // debug

    while (sum < diff || (sum - diff) % 2 != 0)
    {
        sum += i;
        i++;

        // cout << "i=" << i << ", sum=" << sum << endl; // debug
    }
    cout << i - 1 << endl;
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
