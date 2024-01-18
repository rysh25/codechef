
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

void solve()
{
    int N;
    cin >> N;

    vector<int> P(N);
    rep(i, N)
    {
        cin >> P[i];
    }

    // cout << "Start:" << endl; // debug

    if (N == 1 || N == 2)
    {
        cout << -1 << endl;
        return;
    }

    if (N == 4)
    {
        rep(i, N)
        {
            switch (P[i])
            {
            case 1:
                cout << 3 << " ";
                break;
            case 2:
                cout << 4 << " ";
                break;
            case 3:
                cout << 1 << " ";
                break;
            case 4:
                cout << 2 << " ";
                break;
            }
        }
        cout << endl;
        return;
    }

    rep(i, N)
    {
        int a = 0;
        if (N % 2 == 0)
        {
            if (P[i] % 2 == 0)
            {
                a = N - P[i] + 2;
            }
            else
            {
                a = ((N - P[i] - 2 + N) % N);
            }
        }
        else
        {
            if (P[i] % 2 == 0)
            {
                a = N - P[i] - 1;
                if (a == 0)
                {
                    a = N - 1;
                }
            }
            else
            {
                a = N - P[i] + 1;
            }
        }
        cout << a << " ";
        // cout << "p+a=" << P[i] + a << " " << endl; // debug
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
