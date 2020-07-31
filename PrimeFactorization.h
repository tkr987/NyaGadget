#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 素因数分解ライブラリ *****/
	/**
	@note
	計算量O(√n)でnを素因数分解する。
	ans[i]がnだったとき、素因数分解して得られた積のなかにn個の素数iが含まれていることを表す。
	例えば n=12 のとき ans[2]=2、ans[3]=1 となるので 12=2×2×3 と分かる。
	**/
	void PrimeFactorization(long long n, std::map<long long, long long>& ans)
	{
		for (auto i = 2LL; i * i <= n; i++)
		{
			while (n % i == 0) ans[i]++, n /= i;
		}
		if (n != 1) ans[n]++;
	}

	long long PrimeFactorization(long long n, long long x)
	{
		long long ans = 0;
		while (n % x == 0)
		{
			ans++;
			n /= x;
		}
		return ans;
	}
}
