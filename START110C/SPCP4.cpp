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
        int N, K, X;
        cin >> N >> X >> K;
        int boys_r = X % K;
        int girls_r = (N - X) % K;
        // cout << "boys_r=" << boys_r << ", girls_r=" << girls_r << endl;

        cout << abs(boys_r - girls_r) << endl;
    }

    return 0;
}
