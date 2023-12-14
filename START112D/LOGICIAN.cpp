
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

        string S;
        cin >> S;

        bool no = false;

        rep(i, N)
        {
            if (S[i] == '0' || no)
            {
                no = true;
                cout << "NO" << endl;
            }
            else
            {
                if (!no && i == N - 1)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "IDK" << endl;
                }
            }
        }
    }
    return 0;
}
