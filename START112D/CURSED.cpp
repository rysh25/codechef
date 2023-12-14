
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

        sort(A.begin(), A.end());

        ll sum = A[0];
        int ans = 0;
        bool all_greater_than_0 = true;
        for (int i = 1; i < N; i++)
        {
            if (A[i] < 1)
            {
                all_greater_than_0 = false;
            }

            if (sum >= A[i])
            {
                ans++;
            }
            sum += A[i];
        }

        if (!all_greater_than_0)
        {
            ans++;
        }

        cout << ans << endl;
        rep(i, N)
        {
            cout << A[i] << (i < N - 1 ? ' ' : '\n');
        }
    }

    return 0;
}
