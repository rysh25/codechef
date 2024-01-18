
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
    int H, X, Y1, Y2, K;
    cin >> H >> X >> Y1 >> Y2 >> K;

    int n1 = (H + X - 1) / X;

    // cout << "n1=" << n1 << endl; // debug

    int n2 = 0;
    if (H <= Y1 * K)
    {
        n2 = (H + Y1 - 1) / Y1;

        // cout << "1: n2=" << n2 << endl; // debug
    }
    else
    {
        n2 = K;
        H -= Y1 * K;
        n2 += (H + Y2 - 1) / Y2;

        // cout << "2: n2=" << n2 << endl; // debug
    }

    cout << min(n1, n2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
