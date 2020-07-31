#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 素因数分解ライブラリ *****/

	/**
	@brief 素因数分解をする
	@note
	 nを素因数分解する。計算量O(√n)
	 例えば 18 = 2 * 3 * 3 なので res[2] = 1, res[3] = 2 を返す。
	**/
	void NT_PrimeFactorization(long long n, std::map<long long, long long>& res)
	{
		for (long long i = 2; i * i <= n; i++)
		{
			while (n % i == 0) res[i]++, n /= i;
		}
		if (n != 1) res[n]++;
	}

	/**
	@brief 因数を得る
	@note
	 nの因数xを得る。計算量O(log N)
	 例えば nを素因数分解したときx²の因数をもつとき2を返す。
	**/
	long long NT_PrimeFactorization(long long n, long long x)
	{
		long long res = 0;
		while (n % x == 0) res++, n /= x;
		return res;
	}
}
