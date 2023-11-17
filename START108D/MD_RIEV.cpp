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

/**
 * @brief エラトステネスの篩を用いて、素数判定を行います。
 *
 * @tparam T 素数判定を行う数値の型を指定します。
 */
template <typename T>
struct Eratosthenes
{
    /**
     * @brief 素数であるかの判定結果を格納するテーブルです。
     *
     */
    vector<bool> is_prime;

    /**
     * @brief 素数を格納する配列です。
     *
     */
    vector<int> primes;

    /**
     * @brief 素因数分解における最小の素数を格納するテーブルです。
     *
     */
    vector<T> min_factor;

    /**
     * @brief メビウス関数の値を格納するテーブルです。
     *
     */
    vector<T> mobius;

    /**
     * @brief Eratosthenes のコンストラクターです。
     * コンストラクターでは、エラトステネスの篩を用いて、
     * 素数判定を行うためのテーブルを作成します。
     *
     * @param n 素数判定を行う数値の上限を指定します。
     * @details
     * 素数判定を行う数値の上限を n とすると、
     * n 以下の数値が素数かどうかを判定することができます。
     *
     * - Time complexity: O(n log log n)
     * - Space complexity: O(n)
     */
    Eratosthenes(T n) : is_prime(n + 1, true),
                        min_factor(n + 1, -1),
                        mobius(n + 1, 1)
    {
        // 1 は予めふるい落としておく
        is_prime[1] = false;
        min_factor[1] = 1;

        // 篩
        for (long long p = 2; p <= n; ++p)
        {
            // すでに合成数であるものはスキップする
            if (!is_prime[p])
                continue;

            primes.emplace_back(p);

            // p についての情報更新
            min_factor[p] = p;
            mobius[p] = -1;

            // p 以外の p の倍数から素数ラベルを剥奪
            for (long long q = p * 2; q <= n; q += p)
            {
                // q は合成数なのでふるい落とす
                is_prime[q] = false;

                // q は p で割り切れる旨を更新
                if (min_factor[q] == -1)
                    min_factor[q] = p;
                if ((q / p) % p == 0)
                    mobius[q] = 0;
                else
                    mobius[q] = -mobius[q];
            }
        }
    }

    /**
     * @brief 整数 n を素因数分解します。
     *
     * @param n 素因数分解する数値を指定します。
     * @return vector<pair<T, T>> pair (素因数, 指数) の vector としてとして素因数分解の結果を返します。
     * @details
     * min_factor テーブルを用いて、素因数分解を行います。
     * min_factor テーブルは、整数 n を素因数分解した際に、
     * 最小の素数を格納しています。
     * そのため、min_factor[n] を用いて、
     * n の素因数分解を行うことができます。
     *
     * 素因数の個数は、log n 個であることが知られています。
     *
     * 少量の数値を素因数分解する場合、 √n までの試しわり法に比べて、
     * 素数テーブルの作成に時間がかかるため遅くなります。
     * しかし、素数テーブルを作成した後は、
     * 素因数分解を高速に行うことができるため、
     * 大量の数値を素因数分解する場合は、
     * エラトステネスの篩を用いた素因数分解が有効です。
     *
     * - Time complexity:　O(log n)
     * - Space complexity: O(log n)
     */
    vector<pair<T, T>> factorize(T n)
    {
        vector<pair<T, T>> res;
        while (n > 1)
        {
            T p = min_factor[n];
            T exp = 0;

            // n で割り切れる限り割る
            while (min_factor[n] == p)
            {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    /**
     * @brief 整数 n の約数を列挙します。
     *
     * @param n 約数を列挙する数値を指定します。
     * @return vector<T> n の約数を昇順に並べた vector として返します。
     * @details
     * n の約数を列挙するには、n を素因数分解し、
     * 素因数の指数を 0 から最大値まで変化させながら、
     * 約数を列挙することができます。
     *
     * Time complexity: O(log n)
     * Space complexity: O(log n)
     */
    vector<T> divisors(T n)
    {
        vector<T> res({1});

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        for (auto p : pf)
        {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i)
            {
                int v = 1;
                for (int j = 0; j < p.second; ++j)
                {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

bool is_palindrome(string s)
{
    int l, r;
    if (s.size() % 2 == 0)
    {
        l = s.size() / 2 - 1;
        r = s.size() / 2;
    }
    else
    {
        l = s.size() / 2 + 1;
        r = s.size() / 2 + 1;
    }

    while (l >= 0 && r < s.size())
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l--;
        r++;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;

    Eratosthenes e(1e5);

    vector<int> palindromic_primes;
    for (auto p : e.primes)
    {
        if (is_palindrome(to_string(p)))
        {
            palindromic_primes.emplace_back(p);
        }
    }

    while (T--)
    {
        int N;
        cin >> N;

        int event_count = 0;
        int odd_count = 0;
        for (auto p : palindromic_primes)
        {
            string s = to_string(p);
            if (s.size() % 2 == 0)
            {
                event_count++;
            }
            else
            {
                odd_count++;
            }

            if (event_count + odd_count == N)
            {
                cout << event_count << " " << odd_count << endl;
                break;
            }
        }
    }
    return 0;
}
