#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
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

    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % N != 0)
    {
        cout << "No" << endl;
        return;
    }

    int target = sum / N;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
