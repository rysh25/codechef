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

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        string A, B;
        cin >> A >> B;

        int wins = 0;
        int losses = 0;
        int draws = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] == 'R' && B[i] == 'S' ||
                A[i] == 'S' && B[i] == 'P' ||
                A[i] == 'P' && B[i] == 'R')
            {
                wins++;
            }
            else if (A[i] == 'R' && B[i] == 'P' ||
                     A[i] == 'S' && B[i] == 'R' ||
                     A[i] == 'P' && B[i] == 'S')
            {
                losses++;
            }
            else
            {
                draws++;
            }
        }

        // cout << "wins=" << wins << ", losses=" << losses << ", draws=" << draws << endl;

        if (wins > losses)
        {
            cout << 0 << endl;
        }
        else if (wins < losses)
        {
            cout << ((losses - wins) + 2) / 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }

    return 0;
}
