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
        int A, B;
        cin >> A >> B;

        if (A % B == 0)
        {
            // cout << "0: " << A << " " << B << ", A%B=" << A % B << endl;
            cout << 0 << endl;
            continue;
        }

        int a = A;
        int b = B;
        int moves_a = 0;
        while (a % b != 0)
        {
            a -= 1;
            b += 1;
            moves_a++;
            // cout << "A: " << A << " B: " << B << ", ans: " << ans << endl;
        }

        a = A;
        b = B;
        int moves_b = 0;
        while (a % b != 0)
        {
            a += 1;
            b -= 1;
            moves_b++;
            // cout << "A: " << A << " B: " << B << ", ans: " << ans << endl;
        }

        int ans = min(moves_a, moves_b);

        cout << ans << endl;
    }

    return 0;
}
