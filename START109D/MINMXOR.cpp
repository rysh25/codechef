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
        int x = 0;
        rep(i, N)
        {
            cin >> A[i];

            x ^= A[i];

            // bitset<17> bs(A[i]);
            // cout << bs << endl;
        }

        // bitset<17> bs2(x);
        // cout << "xor=" << bs2 << endl;

        int mn = x;
        int mni = 0;
        rep(i, N)
        {
            int a = x ^ A[i];
            if (a < mn)
            {
                mn = a;
                mni = i;
            }
        }

        // cout << "mxi=" << mni << endl;
        // bitset<17> bs3(x ^ A[mni]);
        // cout << "xor2=" << bs3 << endl;

        cout << mn << endl;
    }

    return 0;
}
