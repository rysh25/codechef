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

int f(int X, int N, int K)
{
    return (X % K) * ((N - X) % K);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int K;
        cin >> K;

        for (int i = 0; i < N; i++)
        {
            cout << f(i, N, K) << " ";
        }
        cout << endl;

        cout << "K=" << K << endl;

        for (int i = 0; i <= N; i++)
        {
            cout << "i=" << i << ", i%K=" << i % K << endl;
        }
        for (int i = 0; i <= N; i++)
        {
            cout << "N-i=" << N - i << ", (N-i)%K=" << (N - i) % K << endl;
        }
        cout << endl;

        int a = min(N, K) / 2;
        int b = ((N % K) + (min(N, K) / 2) % K);

        cout << "a=" << a << ", b=" << b << endl;
        cout << "a*b=" << a * b << endl;
    }

    return 0;
}
