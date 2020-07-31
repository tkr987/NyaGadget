#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{	/***** 数え上げライブラリ *****/

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
}
