
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

        if (N == 4)
        {
            if (A[0] + A[1] == A[2] + A[3])
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            bool all_equal = true;
            rep(i, N - 1)
            {
                if (A[i] != A[i + 1])
                {
                    all_equal = false;
                    cout << "YES" << endl;
                    break;
                }
            }

            if (all_equal)
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
