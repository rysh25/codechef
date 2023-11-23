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

        vector<int> B(N);
        vector<int> even;
        vector<int> odd;
        rep(i, N)
        {
            cin >> B[i];
            if (B[i] % 2 == 0)
            {
                even.emplace_back(B[i]);
            }
            else
            {
                odd.emplace_back(B[i]);
            }
        }

        sort(odd.rbegin(), odd.rend());

        // cout << "odd: ";
        // for (auto o : odd)
        // {
        //     cout << o << " ";
        // }
        // cout << endl;

        sort(even.rbegin(), even.rend());

        // cout << "even: ";
        // for (auto e : even)
        // {
        //     cout << e << " ";
        // }
        // cout << endl;

        auto calc_ab = [&](int x, int y)
        {
            int l = -1;
            int r = 1e5 + 1;

            // cout << "l=" << l << ", r=" << r << endl;

            while (r - l > 1)
            {
                int m = l + (r - l) / 2;
                // cout << "m=" << m << endl;

                if (m - (y - m) == x)
                {
                    return m;
                }
                else if (m - (y - m) > x)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }

            return -1;
        };

        vector<int> ans;
        vector<int> ans_e1;
        vector<int> ans_e2;
        // cout << "even: " << endl;
        for (int i = 0; i < even.size() / 2; i++)
        {
            int y = even[i];
            int x = even[i + even.size() / 2];
            // cout << "x=" << x << ", y=" << y << endl;
            int a = calc_ab(x, y);
            if (a == -1)
            {
                cout << -1 << endl;
                return 0;
            }
            // cout << "a=" << a << ", b=" << y - a << endl;

            ans_e1.emplace_back(a);
            ans_e2.emplace_back(y - a);
            ans.emplace_back(a);
            ans.emplace_back(y - a);
        }

        vector<int> ans_o1;
        vector<int> ans_o2;
        // cout << "odd: " << endl;
        for (int i = 0; i < odd.size() / 2; i++)
        {
            int y = odd[i];
            int x = odd[i + odd.size() / 2];
            // cout << "x=" << x << ", y=" << y << endl;
            int a = calc_ab(x, y);
            // cout << "a=" << a << ", b=" << y - a << endl;
            if (a == -1)
            {
                cout << -1 << endl;
                return 0;
            }

            ans_o1.emplace_back(a);
            ans_o2.emplace_back(y - a);
            ans.emplace_back(a);
            ans.emplace_back(y - a);
        }

        // // sort(ans.rbegin(), ans.rend());
        // for (auto a : ans)
        // {
        //     cout << a << " ";
        // }

        if (ans_e1.size() == 0 && ans_o1.size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }

        for (auto ans_e : ans_e1)
        {
            cout << ans_e << " ";
        }
        for (auto ans_o : ans_o1)
        {
            cout << ans_o << " ";
        }
        for (auto ans_e : ans_e2)
        {
            cout << ans_e << " ";
        }
        for (auto ans_o : ans_o2)
        {
            cout << ans_o << " ";
        }
        cout << endl;
    }

    return 0;
}
