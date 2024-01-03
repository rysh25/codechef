
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

        vector<int> A(N), B(N);

        rep(i, N)
        {
            cin >> A[i];
        }
        rep(i, N)
        {
            cin >> B[i];
        }

        sort(A.begin(), A.end());
        sort(B.rbegin(), B.rend());

        bool ok = true;
        int sum = A[0] + B[0];
        rep(i, N)
        {
            if (A[i] + B[i] != sum)
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            rep(i, N)
            {
                cout << A[i] << " ";
            }
            cout << endl;
            rep(i, N)
            {
                cout << B[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
