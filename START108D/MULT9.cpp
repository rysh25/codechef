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
        string digits;
        cin >> digits;

        int sum = 0;
        int min_q = 0;
        int max_q = 0;
        for (int i = 0; i < N; i++)
        {
            if (digits[i] == '?')
            {
                if (i == 0)
                {
                    min_q += 1;
                    max_q += 9;
                }
                else
                {
                    min_q += 0;
                    max_q += 9;
                }
            }
            else
            {
                sum += digits[i] - '0';
            }
        }

        int ans = 0;
        for (int i = sum + min_q; i <= sum + max_q; i++)
        {
            cout << "i=" << i << endl;
            if (i % 9 == 0)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
