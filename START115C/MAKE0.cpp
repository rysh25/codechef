
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

int main()
{
    int T;

    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        rep(i, N) cin >> A[i];

        // cout << "A: ";
        // rep(i, N) cout << A[i] << " ";
        // cout << endl;

        vector<int> prefix_min_index(N, -1);

        int min_index = -1;
        int min_value = 1e9 + 10;

        rep(i, N)
        {
            if (A[i] < min_value)
            {
                min_value = A[i];
                min_index = i;
            }
            prefix_min_index[i] = min_index;
        }

        // cout << "prefix_min_index: ";
        // rep(i, N) cout << prefix_min_index[i] << " ";
        // cout << endl;

        vector<ll> operations(N, 0);
        ll ans = 0;
        for (int i = N - 1; i >= 1; i--)
        {
            if (A[prefix_min_index[i]] - ans > 0)
            {
                ans += (ll)A[prefix_min_index[i]] - ans;
            }
            operations[i] = ans;
        }
        operations[0] = ans;

        // cout << "operations: ";
        // rep(i, N) cout << operations[i] << " ";
        // cout << endl;

        for (int i = 0; i < N; i++)
        {
            if ((ll)A[i] - operations[i] > 0)
            {
                ans++;
            }
        }

        // cout << "ans=" << ans << endl;

        if (ans > (ll)N)
        {
            cout << N << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}
