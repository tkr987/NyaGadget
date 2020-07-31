#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** 約数列挙ライブラリ *****/

	/**
	@brief 約数を列挙する
	@param
	 nの約数をansに全て格納する。
	 計算量O(sqrt(N))、約数の個数はlog(N)程度になる。
	**/
	void NT_DivisorTable(long long n, std::vector<long long>& ans)
	{
		for (auto i = 1LL; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				ans.push_back(i);
				if (i * i == n) continue;
				ans.push_back(n / i);
			}
		}
		sort(ans.begin(), ans.end());
	}
}
