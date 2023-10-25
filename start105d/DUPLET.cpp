#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
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
    int N; // Odd
    cin >> N;

    cout << N << " " << N - 1 << endl;

    // cout << "N=" << N << endl;

    // for (int i = 1; i <= N; i += 2)
    // {
    //     for (int j = i; i * j <= N; j += 2)
    //     {
    //         if (i * j == N)
    //         {
    //             // cout << "i=" << i << ", j=" << j << endl;

    //             cout << max(i, j) << " " << max(i, j) - 1 << endl;

    //             return;

    //             // for (int k = 1; k <= max(i, j); k += 2)
    //             // {
    //             //     for (int l = 0; l <= max(i, j); l += 2)
    //             //     {
    //             //         if (((k | l) == i && (k ^ l) == j) ||
    //             //             ((k | l) == j && (k ^ l) == i))
    //             //         {
    //             //             // cout << "k=" << k << ", l=" << l << endl;
    //             //             cout << k << " " << l << endl;
    //             //             return;
    //             //         }
    //             //     }
    //             // }
    //         }
    //     }
    // }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
