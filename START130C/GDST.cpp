
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
    string S;
    cin >> S;

    if (N % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    // cerr << "S=" << S << endl;

    vector<int> ans;
    rep(i, N / 2)
    {
        // cerr << "i=" << i << endl;
        if (S[i * 2 + 1] != S[i * 2])
        {
            if (ans.size() == 0 ||
                S[ans.back() - 1] != S[i * 2 + 1])
            {
                // cerr << "1: pushing " << i * 2 + 2 << endl;
                ans.push_back(i * 2 + 2);
            }
            else
            {
                // cerr << "2: pushing " << i * 2 + 1 << endl;
                ans.push_back(i * 2 + 1);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
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
