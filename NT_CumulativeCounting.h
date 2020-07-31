#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** 数え上げ高速化ライブラリ *****/

	template< typename T > struct NT_CumulativeCounting
	{	// 引数にModライブラリを渡すことを想定
		// O(N)で階乗の累積テーブルを事前に作成しておくことで
		// O(1)で組み合わせ数を返すことを可能にする
		vector< T > fv, fvinv, inv;

		NT_CumulativeCounting(long long maxsize)
		{	// Hがn+r-1なので、vsizeをmaxsize * 2とする
			long long vsize = maxsize * 2;
			fv.resize(vsize + 1);
			fvinv.resize(vsize + 1);
			inv.resize(vsize + 1);
			fv[0] = fvinv[vsize] = inv[0] = 1;

			for (long long i = 1; i < vsize + 1; i++)
				fv[i] = fv[i - 1] * i;
			fvinv[vsize] /= fv[vsize];

			for (long long i = vsize - 1; -1 < i; i--)
				fvinv[i] = fvinv[i + 1] * (i + 1);

			for (long long i = 1; i < vsize + 1; i++)
				inv[i] = fvinv[i] * fv[i - 1];
		}

		T Factorial(long long k) { return fv[k]; }
		T FactorialInv(long long k) { return fvinv[k]; }
		T Inv(long long k) { return inv[k]; }

		T P(long long n, long long r)
		{
			if (r < 0 || n < r) return 0;
			return Factorial(n) * FactorialInv(n - r);
		}

		T C(long long n, long long r)
		{
			if (r < 0 || n < r) return 0;
			return Factorial(n) * FactorialInv(r) * FactorialInv(n - r);
		}

		T H(long long n, long long r)
		{
			if (n < 0 || r < 0) return 0;
			return (r == 0) ? 1 : C(n + r - 1, r);
		}

		T Catalan(long long n)
		{
			return C(2 * n, n) - C(2 * n, n - 1);
		}
	};
}
