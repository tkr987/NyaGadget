#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 素数テーブルライブラリ *****/

	void PrimeTable(long long n, std::vector<long long>& res)
	{
		std::vector<bool> test(n + 1, true);
		test[0] = test[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!test[i]) continue;
			for (long long j = 2 * i; j <= n; j += i) test[j] = false;
		}
		res.clear();
		for (auto i = 0LL; i < (long long)test.size(); i++)
		{
			if (test[i]) res.push_back(i);
		}
	}

	void PrimeTable(long long n, std::vector<bool>& res)
	{
		res.resize(n + 1, true);
		res[0] = res[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!res[i]) continue;
			for (auto j = 2LL * i; j <= n; j += i) res[j] = false;
		}
	}
}
