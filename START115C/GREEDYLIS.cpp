
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
        int N, X;
        cin >> N >> X;

        if (X == 0)
        {
            rep(i, N) cout << i + 1 << " ";
            cout << endl;
            continue;
        }

        int alicelis = N - 1 - X; // アリスの LIS
        // cout << "N=" << N << ", X=" << X << endl;
        // cout << "N-1=" << N - 1 << endl;
        // cout << "alicelis=" << alicelis << endl;
        if (alicelis <= 0)
        {
            cout << -1 << endl;
            continue;
        }
        else if (alicelis == 1)
        {
            cout << N;
            rep(i, N - 1) cout << " " << i + 1;
            cout << endl;
            continue;
        }

        int a2_back = alicelis - 2; // 2番目より大きな要素の個数
        int a2 = N - a2_back;       // 2番目の要素

        cout << 1 << " ";
        cout << a2 << " ";

        for (int i = 2; i <= N; i++)
        {
            if (i == a2)
                continue;
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
