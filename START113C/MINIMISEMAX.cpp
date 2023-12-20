
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
        int X, Y;
        cin >> X >> Y;

        if (X > Y)
        {
            // cout << "X=" << X << ", Y=" << Y << endl;
            // cout << "1: " << X - Y * 2 << endl;
            // cout << "2: " << X + Y / Y + 1 << endl;
            cout << max(max(1, X - Y * 2), ((X + Y) / (Y + 1))) << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
