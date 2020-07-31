#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** MOD上のLCMライブラリ *****/

	struct NT_NyaaModLCM
	{
		/**
		@brief 最小公倍数の計算
		@param v lcmを求める集合
		@return 計算結果 lcm
		@note
		 lcmを求める集合の個数が多いとLCMは簡単にオーバーフローする。
		 そこで、テンプレート引数にmod型を渡す。
		 計算量はO(N√M), N=集合の個数、M=集合の各要素v[i]
		**/
		template <class T> static T Run(const vector<long long>& v)
		{
			map<long long, long long> nyaa;
			for (auto& e : v)
			{
				map<long long, long long> res;
				PrimeFactorization(e, res);
				for (auto& e : res) nyaa[e.first] = max(nyaa[e.first], e.second);
			}
			T lcm = 1;
			for (auto& e : nyaa) lcm *= NT_Counting<T>::Pow(e.first, e.second);
			return lcm;
		}

		template< typename T > struct NT_Counting
		{	// 引数にModライブラリを渡すことも可能

			static T P(long long n, long long r)
			{
				if (r < 0 || n < r) return 0;

				T res = 1;
				for (long long i = n; n - r < i; i--) res *= i;
				return res;
			}

			static T C(long long n, long long r)
			{
				if (r < 0 || n < r) return 0;

				T res = 1;
				for (long long i = n; n - r < i; i--) res *= i;
				for (long long i = r; 0 < i; i--) res /= i;
				return res;
			}

			static T H(long long n, long long r)
			{
				if (n < 0 || r < 0) return 0;
				return (r == 0) ? 1 : C(n + r - 1, r);
			}

			static T Catalan(long long n)
			{
				return C(2 * n, n) - C(2 * n, n - 1);
			}

			/**
			@brief 累乗の計算
			@note
			 繰り返し自乗法でxのn乗を返す。計算量O(logN)
			**/
			static T Pow(long long x, long long n)
			{
				T res = 1;
				if (0 < n)
				{
					res = Pow(x, n / 2);
					res = res * res;
					if (n % 2 != 0) res *= x;
				}
				return res;
			}
		};

		/**
		@brief 素因数分解ライブラリ
		@note
		 nを素因数分解する。計算量O(√n)
		 ans[i]がnだったとき、素因数分解して得られた積のなかにn個の素数iが含まれていることを表す。
		 例えば n=12 のとき ans[2] = 2, ans[3] = 1 となるので 12 = 2 * 2 * 3 と分かる。
		**/
		static void PrimeFactorization(long long n, map<long long, long long>& res)
		{
			for (long long i = 2; i * i <= n; i++)
			{
				while (n % i == 0)
				{
					res[i]++;
					n /= i;
				}
			}
			if (n != 1) res[n]++;
		}
	};
};