
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
        ll N, M;
        cin >> N >> M;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];

        sort(A.rbegin(), A.rend());

        ll ans = 0;

        ll prev = A[0];
        for (int i = 1; i < N; i++)
        {
            if (A[i] < prev)
            {
                // cout << "((N - i + M - 1) / M)=" << ((N - i + M - 1) / M) << endl;
                // cout << "(prev - A[i])=" << (prev - A[i]) << endl;
                // cout << "ans+=" << ((N - i + M - 1) / M) * (prev - A[i]) << endl;
                ans += ((N - i + M - 1) / M) * (prev - A[i]);
            }
            prev = A[i];
        }

        cout << ans << endl;
    }

    return 0;
}
