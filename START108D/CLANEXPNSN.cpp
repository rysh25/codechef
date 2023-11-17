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
        map<int, int> prev_index;
        map<int, int> max_len;
        vector<int> A(N);
        rep(i, N)
        {
            cin >> A[i];
        }

        for (int i = 0; i < N; i++)
        {
            if (prev_index.count(A[i]) > 0)
            {
                max_len[A[i]] = max(max_len[A[i]], (i - prev_index[A[i]] - 1 + 1) / 2);
                prev_index[A[i]] = i;
            }
            else
            {
                prev_index[A[i]] = i;
                max_len[A[i]] = i;
            }
        }

        for (auto pi : prev_index)
        {
            max_len[pi.first] = max(max_len[pi.first], N - pi.second - 1);
        }

        int min_clan = -1;
        int min_len = INT_MAX;
        for (auto ml : max_len)
        {
            // cout << "!!!" << ml.first << " " << ml.second << endl;
            if (ml.second < min_len)
            {
                min_len = ml.second;
                min_clan = ml.first;
            }
        }

        cout << min_clan << " " << min_len << endl;
    }
    return 0;
}
